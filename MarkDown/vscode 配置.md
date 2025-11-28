VScode 是一款非常强大的代码/文本编辑器。至于它为什么强大请看下图。

![](https://cdn.luogu.com.cn/upload/image_hosting/ttrdt8hs.png)

## 重置 vscode

1. 卸载直接运行安装目录下的 `unins000.exe`。

2. 来到 `C:\Users\admin\AppData\Roaming` 其中 `admin` 是你系统用户名，删除 `Code`文件夹。

![](https://cdn.luogu.com.cn/upload/image_hosting/jurgg2th.png)

3. 来到 `C:\Users\admin` 同样 `admin` 是你系统用户名。删除 `.vscode` 文件夹。

![](https://cdn.luogu.com.cn/upload/image_hosting/daq2brd6.png)

恭喜，你完成了第一步卸载 vscode。

## 安装 vscode

这里给出 vscode 官方下载地址：<https://code.visualstudio.com/download>。

安装过程我就不再赘述了。

## 对于 C/C++ 选手

### 安装 C/C++ 编译器

这里给出 Mingw64 官方下载地址：<https://www.mingw-w64.org/source/>。

下载后放在 D 盘方便我们后面的处理。

![](https://cdn.luogu.com.cn/upload/image_hosting/pqtnd0cy.png)

这一步非常重要请看仔细了。右键`此电脑`，点击`属性`，点击`高级系统设置`，点击`环境变量`，双击系统变量中的 `Path`，点击`新建`，将 `D:\mingw64\bin`（就是 mingw64 中的 `bin` 文件夹的路径） 粘进去。保存点三个`确定`即可。（也可以参照下图）。

![](https://cdn.luogu.com.cn/upload/image_hosting/mx0b7scp.png)

`win+r` 输入 `cmd` 依次输入 `g++ -v`，`gcc -v`，`gdb -v`，看是否报错，如出现 `...不是内部或外部命令，也不是可运行的程序或批处理文件。`那就是你配置有误，请重新配置。

### 配置 C/C++ 环境

`ctrl+shift+x` 打开扩展，搜索 `C/C++` 扩展并安装。

![](https://cdn.luogu.com.cn/upload/image_hosting/m1u6bmiy.png)

然后打开一个文件夹（**文件夹和内部文件名不得包含中文或全角符号否则报错**），新建一个 cpp 文件，敲出一个 `hello world`，如果你使用万能头报错，那是正常的，配置后就不报错了。

单击菜单栏上的 `Terminal(终端)->Configure Default Build Task` 。随后在跳出的选择方框中点击 **`C/C++: g++.exe build active file`** 以**编译 `helloworld.cpp`** 并创建**可执行文件 `helloworld.exe`**。

这样，我们会发现在左侧的文件夹栏目中出现了 `.vscode` 文件夹，其中含有 **`tasks.json`** 文件，我们打开该文件，并输入如下代码（里面需要修改的地方我写注释里了）：

```json
{
    "tasks": [
        {
            "type": "cppbuild",
            "label": "C/C++: g++.exe 生成活动文件",
            "command": "D:\\mingw64\\bin\\g++.exe", //这里改成输入你的 g++.exe 路径
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "${file}",
                "-o",
                "${fileDirname}\\${fileBasenameNoExtension}.exe"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "调试器生成的任务。"
        }
    ],
    "version": "2.0.0"
}
```

接下来，我们进一步进行配置。该配置是针对于程序运行的，点击 **`Run（运行）->Add Configuration（添加配置）`**，这样会在 `.vscode` 文件夹中生成 **`launch.json`** 文件，我们打开并输入如下代码（里面需要修改的地方我写注释里了）：

```json
{
    "configurations": [
    {
        "name": "(gdb) 启动",
        "type": "cppdbg",
        "request": "launch",
        "program": "${fileDirname}\\${fileBasenameNoExtension}.exe",
        "args": [],
        "stopAtEntry": false,
        "cwd": "${fileDirname}",
        "environment": [],
        "externalConsole": false,
        "MIMode": "gdb",
        "miDebuggerPath": "D:/mingw64/bin/gdb.exe",//这里改成输入你的 gdb.exe 路径
        "setupCommands": [
            {
                "description": "为 gdb 启用整齐打印",
                "text": "-enable-pretty-printing",
                "ignoreFailures": true
            },
            {
                "description": "将反汇编风格设置为 Intel",
                "text": "-gdb-set disassembly-flavor intel",
                "ignoreFailures": true
            }
        ],
        "preLaunchTask": "C/C++: g++.exe 生成活动文件"
    }
    ]
}
```

接下来，我们进行最后一项的配置。该配置时针对于C/C++的相关拓展的，我们首先按下 `Ctrl+Shift+P` 以打开全局搜索，输入C/C++并在搜索结果中选择 `C/C++: Edit configurations(UI)`

![](https://cdn.luogu.com.cn/upload/image_hosting/f6ufwg94.png)

![](https://cdn.luogu.com.cn/upload/image_hosting/qxwyi2e1.png)

![](https://cdn.luogu.com.cn/upload/image_hosting/mhu47lbx.png)

ok，现在你可以发现 `.vscode` 文件夹中不知不觉有了一个 `c_cpp_properties.json` 。

现在 vscode 就配置完成了，`Ctrl + F5` (运行) 刚才写的 `helloworld.cpp` 如果下方弹出一个框，过一会，你看到了 `hello world`出现那就说明你配置成功了。你还可以打上断点按下 `F5` 再按下 `ctrl+shift+d` 你就可以在旁边看到调试信息了。

## 对于 Python 选手

### 下载 Python 解释器

链接：<https://www.python.org/downloads/>。

选择合适的安装程序下载。

打开安装程序，**请按下面的图片安装，否则会出问题**。

![](https://cdn.luogu.com.cn/upload/image_hosting/6tlsyyve.png)

![](https://cdn.luogu.com.cn/upload/image_hosting/s74w6gw2.png)

![](https://cdn.luogu.com.cn/upload/image_hosting/xhke5zbj.png)

![](https://cdn.luogu.com.cn/upload/image_hosting/r5oueh8a.png)

![](https://cdn.luogu.com.cn/upload/image_hosting/y55ijgbt.png)

至此，Python 解释器就安装完成了。

### 配置 Python 环境

#### 安装必要插件

进入 vscode，安装 `Python` 插件。

![](https://cdn.luogu.com.cn/upload/image_hosting/uw122kvs.png)

装好后，建议重启 vscode。

#### 选择解释器

按下 `Ctrl+Shift+P`，输入 `Python: Select Interpreter`。

在弹出的框框中选择你安装的解释器。

![](https://cdn.luogu.com.cn/upload/image_hosting/okxgpgn5.png)

#### 创建环境（可选）

按下 `Ctrl+Shift+P`，输入 `Python: Create Environment...`。

![](https://cdn.luogu.com.cn/upload/image_hosting/9tu4h69n.png)

选择 Venv。

![](https://cdn.luogu.com.cn/upload/image_hosting/p2h6i64m.png)

选择解释器。

![](https://cdn.luogu.com.cn/upload/image_hosting/tp06n5x8.png)

直到出现上图弹窗才算成功。

然后你就可以快乐地运行 Python 代码了。

## 个性化你的 vscode

### 中文

安装插件：`Chinese (Simplified) (简体中文) Language Pack for Visual Studio Code`。

### 代码片段

点击小齿轮按钮，然后点击代码片段。

![](https://cdn.luogu.com.cn/upload/image_hosting/zl6ojs2w.png)

在弹出的框框里选择 `cpp.json`。

![](https://cdn.luogu.com.cn/upload/image_hosting/wfjie62y.png)

里面会有这么一段东西：

```json
{
	// Place your snippets for cpp here. Each snippet is defined under a snippet name and has a prefix, body and 
	// description. The prefix is what is used to trigger the snippet and the body will be expanded and inserted. Possible variables are:
	// $1, $2 for tab stops, $0 for the final cursor position, and ${1:label}, ${2:another} for placeholders. Placeholders with the 
	// same ids are connected.
	// Example:
	// "Print to console": {
	// 	"prefix": "log",
	// 	"body": [
	// 		"console.log('$1');",
	// 		"$2"
	// 	],
	// 	"description": "Log output to console"
	// }
}
```

注意看 Example 中的部分：

- `"Print to console"`：代码片名称。
  
- `"prefix"："log"` 触发词，输入 log 的时候触发。

- `"body"`：代码片的内容，触发之后会用什么内容来替换触发词。

- `"description": "Log output to console"` 代码片描述，不一定非得加。

很显然中间 body 里面的那一堆代码手动打起来很麻烦，提供一个 C++ 程序，可以格式化。

```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    bool flag=1;
    while(1){
        getline(cin,s);
        if(s[0] == '~') break;
        else if(!flag) cout << "," << "\n";
        flag = 0;
        cout << '"' << s << '"';
    }
    cout << endl;
	return 0;
} 
```

注意事项：

1. 注意使用的时候最后需要换行并输入一个 `~` 符号，不然会死循环。

2. 你要格式化的代码中不要使用 tab，请用四个空格代替。

3. 还有注意如果不是最后一个，需要加 `,` 在末尾。

这里是我的代码片段：<https://www.luogu.me/paste/2scl6dyi>。

### 字体

我推荐 FiraCode 字体，在[这里](https://github.com/tonsky/FiraCode)下载。

解压安装 ttf 文件夹里的字体（全都安装）。

再下载 Super OTC 字体，在[这里](https://github.com/notofonts/noto-cjk/blob/main/Sans/README.md)下载。

然后解压安装字体。

然后在按下 `Ctrl+,` 点击下图的按钮。

![](https://cdn.luogu.com.cn/upload/image_hosting/0tb5yhvi.png)

在打开的文件里加入这一段代码：

```json
"terminal.integrated.fontFamily": "'Fira Code', 'Noto Sans CJK SC'",
"editor.fontFamily": "'Fira Code', 'Noto Sans CJK SC'",
"editor.fontLigatures": "'cv01', 'cv02', 'zero'",
```

如果是最后一行不需要加最后的逗号。

### MarkDown

装以下插件：

- Markdown All in One

- Markdown PDF

- Markdown Preview Enhanced

- Markdown TOC

- Markdown+Math

- vscode-pdf

在 `C:\Users\admin\.vscode\extensions\yzane.markdown-pdf-1.5.0\template` 用代码编辑器打开 `template.html` 文件。

在 `</body>` 和 `</html>` 之间添加代码如下：

```html
<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>
<script type="text/x-mathjax-config"> MathJax.Hub.Config({ tex2jax: {inlineMath: [['$', '$']]}, messageStyle: "none" });</script>
```

然后你需要确保你的电脑中装有 Google Chrome 浏览器。

再在刚刚打开的全局配置文件中添加：

```json
"markdown-pdf.executablePath": "C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe", //这是你 Chrome 内核的路径
```

导出为 PDF 方法：

先创建好 Markdown 文件，然后右键找到并点击 MPE: 打开侧边预览，然后在预览里右键，找到 ExPort，选择 Chrome(Putpeteer) 里面的 PDF 然后就可以导出了。

### 推荐的主题

颜色主题：One Dark Pro。

文件图标主题：Material Icon Theme。

产品图标主题：Fluent Icons。

使用方法：安装 `One Dark Pro` 和 `Material Icon Theme` 和 `Fluent Icons` 插件即可。

### 推荐的插件

1. Code Runner：一键运行代码。

2. filesize：显示文件大小

3. CPH NG：相比于传统 CPH 更加高级，详见：<https://www.luogu.com.cn/article/8ix5zp4w>。

4. Error Lens：显示错误信息。

5. CodeGeeX: AI Coding Assistant：代码自动补全，不需登录，~~当然登录了更好~~，但是如果这个用多了可能就不会写代码了，建议在快比赛的时候禁用。

6. vscode-luogu：在 vscode 上洛谷，支持题目传送至 cph，可以支持 CPH NG。

更多好用的扩展详见：<https://www.luogu.com.cn/article/m3oxrdoc>。

## AD

宣团：<https://www.luogu.com.cn/team/108749>。

欢迎符合[条件](https://www.luogu.me/paste/qqzka4i4)的各路大佬加入。