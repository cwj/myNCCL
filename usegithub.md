##use git
	1.先在github上创建一个repository，例如叫myNCCL
	2.安装git客户端，进入客户端
	3.运行命令cd ~/.ssh检查自己的电脑是否存在ssh keys
  	如果提示no such file or directory 则创建一个SSH
  	创建SSH KEYS
  	运行命令：$ssh-keygen -t rsa -C "172623720@qq.com" (youself email)
  	回车输入密码
  	这样一个新的keys就创建完成了，上面代码显示，密匙位置放在了C:/Users/用户名/.ssh/文件夹中。（.ssh文件夹可能是	隐藏的，需要查看隐藏文件）
	4.将生产的SSH KEYS添加到github中在 GitHub 网站点击“Account Settings” > 点击 “SSH Public Keys” > 点击 		“Add another public key在本机找到你创建的密匙文件id_rsa.pub ，使用记事本打开，复制里面所有的内容，粘贴到网	站key的文本框中，点击Add Key 保存  
	5.测试一下我们的设置是否正确
  	输入命令：$ ssh -T git@github.com
  	输入yes
  	我本机显示连接关闭，然后我继续执行上诉命令，提示输入passphrase（密码），输入前面自己设置的passphrase。回车登	录成功登录成功登录成功登录成功！

	6：在本地设置Git信息 
	6.1设置用户名和邮箱 
  	$ git config --global user.name "Firstname Lastname" 
  	$ git config --global user.email "your_email@youremail.com" 此处用户名为自己的实际姓名(自定义的)，而非登录用	户名 

	7.开始上传文件
	1.先在本地创建一个目录
 	例如/d/myNCCL(这个名字和github上的库名字一样)
 	mkdir myNCCL
 	cd myNCCL 
 	git init
 	touch homework.c
 	编辑文件  
 	git add homework.c  
 	git commit -m 'first commit'
 	git remote add origin https://github.com/cwj/myNCCL.git
 	git push -u origin master
 	输入用户名：cwj
 	输入密码:XXXXXXX
 
	8.添加文件后上传到github
 	git commit -a -m "second"
 	git add .(代表所有文件)
 	git push -u origin master
 
 