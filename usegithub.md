##use git
	1.����github�ϴ���һ��repository�������myNCCL
	2.��װgit�ͻ��ˣ�����ͻ���
	3.��������cd ~/.ssh����Լ��ĵ����Ƿ����ssh keys
  	�����ʾno such file or directory �򴴽�һ��SSH
  	����SSH KEYS
  	�������$ssh-keygen -t rsa -C "172623720@qq.com" (youself email)
  	�س���������
  	����һ���µ�keys�ʹ�������ˣ����������ʾ���ܳ�λ�÷�����C:/Users/�û���/.ssh/�ļ����С���.ssh�ļ��п�����	���صģ���Ҫ�鿴�����ļ���
	4.��������SSH KEYS��ӵ�github���� GitHub ��վ�����Account Settings�� > ��� ��SSH Public Keys�� > ��� 		��Add another public key�ڱ����ҵ��㴴�����ܳ��ļ�id_rsa.pub ��ʹ�ü��±��򿪣������������е����ݣ�ճ������	վkey���ı����У����Add Key ����  
	5.����һ�����ǵ������Ƿ���ȷ
  	�������$ ssh -T git@github.com
  	����yes
  	�ұ�����ʾ���ӹرգ�Ȼ���Ҽ���ִ�����������ʾ����passphrase�����룩������ǰ���Լ����õ�passphrase���س���	¼�ɹ���¼�ɹ���¼�ɹ���¼�ɹ���

	6���ڱ�������Git��Ϣ 
	6.1�����û��������� 
  	$ git config --global user.name "Firstname Lastname" 
  	$ git config --global user.email "your_email@youremail.com" �˴��û���Ϊ�Լ���ʵ������(�Զ����)�����ǵ�¼��	���� 

	7.��ʼ�ϴ��ļ�
	1.���ڱ��ش���һ��Ŀ¼
 	����/d/myNCCL(������ֺ�github�ϵĿ�����һ��)
 	mkdir myNCCL
 	cd myNCCL 
 	git init
 	touch homework.c
 	�༭�ļ�  
 	git add homework.c  
 	git commit -m 'first commit'
 	git remote add origin https://github.com/cwj/myNCCL.git
 	git push -u origin master
 	�����û�����cwj
 	��������:XXXXXXX
 
	8.����ļ����ϴ���github
 	git commit -a -m "second"
 	git add .(���������ļ�)
 	git push -u origin master
 
 