## 1.git init <dir>
	在指定的目录下创建一个空的git repo。不带参数将在当前目录下创建一个git repo。
## 2.git clone <repo>  
    克隆一个指定repo到本地。指定的repo可以是本地⽂件系统或者由HTTP或SSH指定的远程路径。     
## 3.git config user.name <name>  
	针对当前repo配置⽤户名。使⽤--global参数将配置全局⽤户名。    
## 4.git add <dir> 
	将指定⽬录的所有修改加⼊到下⼀次commit中。把<directory>替换成<file>将添加指定⽂件的修改。    
## 5.git commit -m "<message>"
	提交暂存区的修改，<message>为提交信息。           
## 6.git status
	显示哪些⽂件已被staged、未被staged以及未跟踪(untracked)。
## 7.git log  
	显示全部commit历史  
## 8.git diff    
	⽐较⼯作区和暂存区的修改    
## 9.git reset <file>    
	将<file>从暂存区移除，但保持⼯作区不变。此操作不会修改⼯作区的任何⽂件。  
## 10.git commit -m <message> --amend  
	将当前staged修改合并到最近⼀次的commit中。
## 11.git reflog
	显示本地repo的所有commit⽇志。  
## 12.git branch  
	显示本地repo的所有分⽀。  
## 13.git switch -c <branch>  
	创建并切换到⼀个新的名为<branch>的分⽀。去掉-c参数将切换到⼀个已有分⽀。  
## 14.git merge <branch>   
	将指定<branch>分⽀合并到当前分⽀。  
## 15.git remote add <name> <url>  
	添加⼀个新的远程连接。添加后可使⽤<name>作为指定<url>远程连接的名称。  
## 16.git fetch <remote> <branch>  
	从指定<remote>抓取指定<branch>的所有commit到本地repo。去掉<branch>将抓取远程所有分⽀的修改。  
## 17.git pull <remote>  
	从指定<remote>抓取所有分⽀的commit并⽴刻合并到本地repo。  
## 18.git push <remote> <branch>  
	将本地指定<branch>推送到指定远程<remote>。如果远程没有对应的分⽀，将⾃动在远程创建此分⽀。  
## 19.git log -<limit>  
	限制log的显示数量。例如：”git log -5”仅显示最新5条commit。  
## 20.git log --oneline  
	每⾏显示⼀条commit。  
## 21.git log --author= "<pattern>"   
	按提交者名字搜索并显示commit。  
## 22.git log --grep= "<pattern>"  
	按指定内容搜索并显示commit。  
## 23.git log <since>..<until>  
	显示指定范围的commit。范围参数可以是commit ID、分⽀名称、HEAD或任意相对位置。  
## 24.git log -- <file>  
	仅显示包含指定⽂件修改的commit。  
## 25.git reset  
	移除所有暂存区的修改，但不会修改⼯作区。  
## 26.git reset --hard  
	移除所有暂存区的修改，并强制删除所有⼯作区的修改。  
## 27.git reset <commit>  
	将当前分⽀回滚到指定<commit>，清除暂存区的修改，但保持⼯作区状态不变。  
## 28.git reset --hard <commit>  
	将当前分⽀回滚到指定<commit>，清除暂存区的修改，并强制删除所有⼯作区的修改。  
## 29.git rebase -i <base>  
	以交互模式对当前分⽀做rebase。  
## 30.git pull --rebase <remote>  
	抓取所有远程分⽀，并以rebase模式并⼊本地repo⽽不是merge。  
## 31.git push <remote> --force  
	将本地分⽀推送到远程。不要使⽤--force参数，除⾮你完全明⽩此操作的后果。  
## 32.git push <remote> --tags  
	使⽤push命令并不会⾃动将本地tag推送到远程。加上--tags参数会将所有本地tag推送到远程。  
## 33.git merge <branch>   
    合并指定分支到到当前分支
## 34.git rebase <branch>   
    衍合指定分支到当前分支
## 35.git tag
	列出所有本地标签
## 36.git tag -d <tagname>
	删除标签
