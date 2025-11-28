## 基本环境准备

1. Git 安装地址：<https://git-scm.com/downloads>，选择你合适的系统安装即可。

2. Nodejs 安装地址：<https://nodejs.org>。

有一点要注意的是 Git 安装时如果不知道每一步是什么意思，最好不要改默认设置，一定要添加到 Path，nodejs 也是要添加到 Path。

3. 在 GitHub 上注册一个账号，会点英语的人应该都会，这里就不再过多赘述。

## 在 GitHub 创建个人仓库

![](https://cdn.luogu.com.cn/upload/image_hosting/lnzhis8d.png)

![](https://cdn.luogu.com.cn/upload/image_hosting/2241yaz0.png)

信息填好后点击 `Create repository`。

这里就用别人的图片了，因为我已经创建过了。

![](https://cdn.luogu.com.cn/upload/image_hosting/skfs62cm.png)

![](https://cdn.luogu.com.cn/upload/image_hosting/7zhe6pyc.png)

![](https://cdn.luogu.com.cn/upload/image_hosting/yqj7k14d.png)

![](https://cdn.luogu.com.cn/upload/image_hosting/hry8d5up.png)

这里可能要等两三分钟，因为部署需要时间。

点击图中 `https://xxx.github.io/` 即可浏览到页面。

![](https://cdn.luogu.com.cn/upload/image_hosting/9sbfs95u.png)

## 安装 Hexo

在电脑中选一个合适的位置创建一个文件夹，命名为 Blog，Hexo 框架和以后自己发布的网页都在这个文件夹中。创建好后，用**管理员方式**打开终端，并 `cd` 到这个文件夹。**（文章中所有命令都要在有管理员权限的终端下运行）**

输入命令 `npm install -g hexo-cli` 安装 Hexo。

安装完成后，用以下命令初始化并检测网站雏形：

```cmd
hexo init  // 初始化
hexo g  // 生成静态文件
hexo s  // 启动服务预览
```

注意 `//` 不要打上去了。

等待出现 `Hexo is running at http://localhost:4000` 就说明你完成了第一步。在浏览器中输入 `http://localhost:4000/` 即可看到你的博客页面。

![](https://cdn.luogu.com.cn/upload/image_hosting/balzs66k.png)

## 变更主题

可以在 <https://hexo.io/themes/index.html> 进行主题的挑选更换。

我推荐 Fluid 主题 <https://github.com/fluid-dev/hexo-theme-fluid>。按照 GitHub 上的步骤做即可。

在终端中运行以下命令：

```cmd
hexo clean
hexo g
hexo s
```

再刷新 `http://localhost:4000/` 网址，即可看到新的主题页面。

更换语言：通过修改 Blog 中的**站点配置**文件 `_config.yml` 中的 language，中文 `zh-CN`，英文 `en`。

## 更换站点配置

![](https://cdn.luogu.com.cn/upload/image_hosting/vxjvllfu.png)

![](https://cdn.luogu.com.cn/upload/image_hosting/6577iv86.png)

## 配置 SSH Key

为了避免每次上传都要输入用户名和密码，我们将使用 SSH 免密登录。

鼠标右击打开 `Git Bash`。

![](https://cdn.luogu.com.cn/upload/image_hosting/6lza66z4.png)

若还没有 user.name 和 user.email，先配置：

```bash
git config --global user.name "你的GitHub用户名"
git config --global user.email "你的GitHub注册邮箱"
```

建议将分支改为 `main`：

在 `C:\Users\admin` 中用记事本打开 `.gitconfig`，加一条

```ini
[init]
	defaultBranch = main
```

生成 ssh 密钥文件：

在 git bash 中输入：

```bash
ssh-keygen -t rsa -C "你的GitHub注册邮箱"
```

然后连续三个回车，默认不需要设置密码，然后找到生成的 `C:\Users\admin\.ssh` 文件夹中的 `id_rsa.pub` 密钥，将内容全部复制。

找到 Github Setting keys 页面，新建 new SSH Key。

![](https://cdn.luogu.com.cn/upload/image_hosting/f66sjhrb.png)

![](https://cdn.luogu.com.cn/upload/image_hosting/ehmfgls3.png)

标题随意填，将刚复制的 `id_rsa.pub` 密钥粘贴到 Key 中，最后 Add SSH key。

## 配置评论

我推荐使用 giscus。

可以参考这里 <https://blog.csdn.net/sinat_41212418/article/details/137819858>。

## 连接 Hexo 与 GitHub

获取 ssh 地址：

![](https://cdn.luogu.com.cn/upload/image_hosting/s2dz53wx.png)

打开 Blog 文件中的 `_config.yml` 即**站点配置**文件，翻到最后修改为：

```yaml
deploy:
  type: git
  repo: 刚获取的ssh地址
  branch: main
  url: https://xxx.github.io/ #这里的 xxx 是你的GitHub用户名
```

然后保存。

最后安装 Git 部署插件：（在 blog 根目录终端下执行，而不是在 git bash 里）。

```cmd
npm install hexo-deployer-git --save
```

这时再输入以下命令：

```cmd
hexo clean
hexo g
hexo d //部署到服务上
```

将代码推送到 git 上，再然后**过几分钟**访问 `https://xxx.github.io/`，就能看到部署好的主题页面了。

## 发布文章

在 Blog 中打开终端命令行输入：

```cmd
hexo new "你的文章标题名"
```

接着在 `\Blog\source\_posts` 文件夹中就能看到新建的 markdown 文件，编辑好后重新执行 `hexo clean` `hexo g` `hexo d` 命令就 ok 了。

## 美化

可以参照：<https://www.luogu.com.cn/article/0m9egybe>。

## AD

我的 Blog：<https://lijingshu2014.github.io>，欢迎交换友链。