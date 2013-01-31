#!/bin/bash
CUSER=`id |cut -d"(" -f2 |cut -d")" -f1`

rman_log_file=/home/oracle/rman_log.out
echo >> $rman_log_file
chmod 666 $rman_log_file

ORACLE_BASE=/u01/oracle
ORACLE_HOME=$ORACLE_BASE/product/10.2.0/Db_1
export ORACLE_HOME

ORACLE_SID=kettle
export ORACLE_SID
ORACLE_USER=oracle
export ORACLE_USER

RMAN=$ORACLE_HOME/bin/rman

rman_str="
ORACLE_BASE=/u01/oracle
ORACLE_HOME=$ORACLE_BASE/product/10.2.0/Db_1
export ORACLE_HOME
ORACLE_SID=kettle
export ORACLE_SID

sqlplus -S -L / as sysdba<<EOF
shutdown immediate;
startup mount;
exit
EOF

$RMAN target / <<EOF
RUN
{
BACKUP FORMAT '/home/oracle/back/oralife_%U_%T' database ;
}
EOF

sqlplus -S -L / as sysdba<<EOF
alter database open;
exit
EOF
"
if [ "$CUSER" = "root" ]
then
    echo "Root Command String: $rman_str" >> $rman_log_file
su - $ORACLE_USER -c "$rman_str" >> $rman_log_file
    RSTAT=$?
else
    echo "User Command String: $rman_str" >> $rman_log_file
    /bin/sh -c "$rman_str" >> $rman_log_file
    RSTAT=$?
fi

if [ "$RSTAT" = "0" ]
then
    LOGMSG="ended successfully"
else
    LOGMSG="ended in error"
fi

echo >> $rman_log_file
echo Script $0 >> $rman_log_file
echo ==== $LOGMSG on `date` ==== >> $rman_log_file
echo >> $rman_log_file

exit $RSTAT
