(1)git init  （在当前文件夹）创建本地仓库
	如果向本地仓库中添加文件，文件必须放到工作目录中（.git为本地仓库，.git的上一层目录为工作目录）
(2)git add filename  添加文件到暂存区（此时并没有添加到本地仓库）
	touch hello.txt
	echo "22222222222">hello.txt
	git add hello.txt   此时可以看到heool.txt文件图标左下角有蓝色的加号

(3)git commit 将文件添加到本地仓库
	git commit -m " [NVOS-xxxx] test change"  此时可以看到heool.txt文件图标左下角有绿色的对号
	echo "\n33333333333333">>hello.txt  此时可以看到heool.txt文件图标左下角有红色感叹号
	git add hello.txt
	git commit -m "删除2，添加3，4"
(4)git log 查看（所有）日志
(5)git diff 默认比较工作区暂存区的差异
	git diff 
	diff --git a/hello.txt b/hello.txt
	index c8f6c9b..3df416a 100644
	--- a/hello.txt
	+++ b/hello.txt
	@@ -1,3 +1,4 @@
	\n33333333333333
	\n33333333333333
	\n44444444444444
	+555555555555555



