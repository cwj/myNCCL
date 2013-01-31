
/home/hadoop/sqoop/bin/sqoop export --connect jdbc:oracle:thin:@192.168.119.89:1521:cemproc \
--username userbehavior --password  bfdds06fd --table test_sqoop --columns inHour,ipaddress,sumPageSpeed,totalOpenPage,inDate \
--append  --split-by inDate --target-dir /user/hive/warehouse/ub_reg_avgspeedopenreg \
--hive-table ub_reg_avgspeedopenreg --hive-import --verbose

export --connect jdbc:mysql://XXXX/crm --username XX --password XX --table tb_keyword_data_201104 
--export-dir /user/wanghai01/data/ --fields-terminated-by '\t' 
--lines-terminated-by '\n' --input-null-string '' --input-null-non-string ''

sqoop export --connect jdbc:oracle:thin:@192.168.40.119:1521:SPTDI \
--username CDMA --password sptdi --table CDR_D_DETAIL_LUC --export-dir \
/user/hive/warehouse/pcmd_1x_hive_etl --input-fields-terminated-by ';' \
--input-null-string '\\N' --input-null-non-string '\\N' -m 1

  INDATE        DATE,
  INHOUR        NUMBER(2),
  IPADDRESS     VARCHAR2(20),
  SUMPAGESPEED  NUMBER(8),
  TOTALOPENPAGE NUMBER(8)



hive> select * from ub_reg_avgspeedopenreg;
OK
18      192.168.20.125  29000580        50001   2012-12-19

/hadoop fs -rmr /user/home/log_record_detail