本文将从以下几个方面介绍 WSL 的使用方法：

1. 安装 WSL。
2. WSL 安装一些 OI 必要的依赖。
3. 在 WSL 配置 vim。
4. 运行 C++ 代码。

## 安装 WSL

由于家庭版有很多功能是被限制的，所以是家庭版的就尽快换系统。

以**管理员身份**打开 PowerShell，输入如下命令：

```powershell
wsl --install
```

此时我们重启电脑，再次以**管理员身份**运行 PowerShell。

WSL 可以安装多种不同的 Linux 发行版，我们可以通过如下命令列出可用的分发。

```powershell
wsl --list --online
```

对于 OI 代码编写的话，我强烈推荐 Ubuntu 或者是 Ubuntu-24.04：

```powershell
wsl --install ubuntu
```

或者：

```powershell
wsl --install ubuntu-24.04
```

此时已经完成了 WSL 的安装。

## WSL 安装 OI 必要的依赖。

在开始菜单中打开 Ubuntu，系统会让我们创建一个用户名，这将作为用户文件夹的名字。然后我们需要设置一个密码，请牢记该密码，以后在使用 `sudo` 命令时需要输入该密码。然后我们就可以使用 WSL 了。

运行一下命令：

```bash
sudo apt update && sudo apt upgrade -y # 非常重要
sudo apt install -y build-essential gcc g++ make # 安装 cpp 编译器
sudo apt install -y vim git curl # 安装 vim 等工具
sudo apt install -y clang-format # 用于格式化代码
```

现在你的 OI 必要依赖就安装好了。

## 在 WSL 配置 vim

运行命令：

```bash
vim ~/.vimrc
```

会打开一堆东西，按一下 `i`，切换到插入模式。

输入代码：

```vim
" 基础设置
set number          " 显示行号
set cursorline      " 高亮当前行
set tabstop=4       " Tab 宽度为 4 空格
set shiftwidth=4    " 自动缩进宽度为 4 空格
set expandtab       " 将 Tab 转换为空格
set autoindent      " 自动缩进
set smartindent     " 智能缩进（适合 C/C++）
set encoding=utf-8  " 编码支持
set mouse=a         " 支持鼠标操作
set scrolloff=3     " 光标上下保留 3 行距离
set wrap            " 自动换行（避免长代码超出屏幕）
set backupcopy=yes  " 保存时保留原文件权限
set nobackup        " 禁用备份文件（避免生成 .swp 等干扰）
set nowritebackup
set noswapfile

" C++ 语法高亮与缩进优化
autocmd FileType c,cpp setlocal cindent
autocmd FileType c,cpp setlocal shiftwidth=4
autocmd FileType c,cpp setlocal tabstop=4
autocmd FileType c,cpp setlocal expandtab

" 编译与运行快捷键（F5 编译运行，F6 仅编译）
autocmd FileType cpp nnoremap <F5> :w<CR>:!g++ % -std=c++14 -O2 -o %< && ./%< <CR>
autocmd FileType cpp nnoremap <F6> :w<CR>:!g++ % -std=c++14 -O2 -o %< <CR>

" 代码格式化快捷键（F4，基于 .clang-format）
autocmd FileType c,cpp nnoremap <F4> :%!clang-format<CR>

" 快速注释/取消注释（Ctrl+/）
nmap <C-/> :s/^/\/\//<CR>:noh<CR>
vmap <C-/> :s/^/\/\//<CR>:noh<CR>
nmap <C-\> :s/^\/\///<CR>:noh<CR>
vmap <C-\> :s/^\/\///<CR>:noh<CR>
```

这里定义了一些快捷键：

- `F5`：编译运行。
- `F6`：仅编译。
- `F4`：格式化代码。
- `Ctrl+/`：快速注释/取消注释。

然后按下 `Esc`，输入 `:wq`，表示保存并关闭。

然后输入命令：

```bash
vim ~/.clang-format
```

同样，将代码粘进去，这是我的码风，大家可自行更改：

```vim
---
# 语言: None, Cpp, Java, JavaScript, ObjC, Proto, TableGen, TextProto
Language:        Cpp
BasedOnStyle:  WebKit
# 访问说明符(public、private等)的偏移
AccessModifierOffset: -4
# 开括号(开圆括号、开尖括号、开方括号)后的对齐: Align, DontAlign, AlwaysBreak(总是在开括号后换行)
AlignAfterOpenBracket: Align
# 对齐数组列
AlignArrayOfStructures: None
# 连续赋值时，对齐所有等号
AlignConsecutiveAssignments: None
# 对齐连续位字段
AlignConsecutiveBitFields: None
# 连续声明时，对齐所有声明的变量名
AlignConsecutiveDeclarations: None
# 对齐连续宏定义
AlignConsecutiveMacros: AcrossComments
# 逃脱换行(使用反斜杠换行)的反斜杠
AlignEscapedNewlines: Left
# 操作数对齐方式
AlignOperands:   Align
# 尾随的注释对齐
AlignTrailingComments: true
# 允许函数参数在一行
AllowAllArgumentsOnNextLine: true
# 允许函数声明的所有参数在放在一行
AllowAllParametersOfDeclarationOnNextLine: true
# 允许短的块放在同一行
AllowShortBlocksOnASingleLine: true
# 允许短的case标签放在同一行
AllowShortCaseLabelsOnASingleLine: true
# 允许短的枚举放在同一行
AllowShortEnumsOnASingleLine: true
# 允许短的函数放在同一行
AllowShortFunctionsOnASingleLine: Empty
# 允许短的if语句保持在同一行
AllowShortIfStatementsOnASingleLine: false
# 允许短的匿名函数lamda表达式放在同一行
AllowShortLambdasOnASingleLine: Empty
# 允许短的循环while保持在同一行
AllowShortLoopsOnASingleLine: false
# 总是在返回类型后换行
AlwaysBreakAfterReturnType: None
# 总是在多行string字面量前换行
AlwaysBreakBeforeMultilineStrings: false
# 总是在template声明后换行
AlwaysBreakTemplateDeclarations: MultiLine
# 宏属性
AttributeMacros: ['__capability', '__output', '__ununsed']
# 表示函数实参要么都在同一行，要么都各自一行
BinPackArguments: true
# false表示所有形参要么都在同一行，要么都各自一行
BinPackParameters: true
# 位域冒号对齐方式
BitFieldColonSpacing : Both
# 大括号换行，只有当BreakBeforeBraces设置为Custom时才有效，设置其他配置则下面不生效
BraceWrapping :
  # class定义后面
  AfterClass: false
  # 控制语句后面
  AfterControlStatement:  false
  # enum定义后面
  AfterEnum:  false
  # 函数定义后面
  AfterFunction:  false
  # 命名空间定义后面
  AfterNamespace: false
  # ObjC定义后面
  AfterObjCDeclaration: false
  # struct定义后面
  AfterStruct:  false
  # union定义后面
  AfterUnion: false
  # catch之前
  BeforeCatch:  false
  # else之前
  BeforeElse: false
  # 缩进大括号
  IndentBraces: false
  # unknown:
  AfterCaseLabel:  false
  AfterExternBlock: false
  BeforeLambdaBody: false
  BeforeWhile: false
  SplitEmptyFunction: false
  SplitEmptyRecord: false
  SplitEmptyNamespace: false
# 在java字段的注释后换行
BreakAfterJavaFieldAnnotations: false
# 在二元运算符前换行
BreakBeforeBinaryOperators: None
# 在大括号前换行
BreakBeforeBraces: Custom
# 在concept前换行
# BreakBeforeConceptDeclarations: Never
# 在三元运算符前换行
BreakBeforeTernaryOperators: true
# 构造函数初始值设定项换行样式
BreakConstructorInitializers: BeforeColon
# 继承列表样式
BreakInheritanceList: AfterColon
# 字符串换行样式
BreakStringLiterals: false
# 每行字符的限制，0表示没有限制
ColumnLimit:     80
# 描述具有特殊意义的注释的正则表达式，它不应该被分割为多行或以其它方式改变
CommentPragmas:  '^ IWYU pragma:'
# 在新行上声明每个命名空间
CompactNamespaces: false
# 构造函数的初始化列表的缩进宽度
ConstructorInitializerIndentWidth: 4
# 延续的行的缩进宽度
ContinuationIndentWidth: 4
# 去除C++11的列表初始化的大括号{后和}前的空格
Cpp11BracedListStyle: true
# 继承最常用的换行方式
DeriveLineEnding: true
# 继承最常用的指针和引用的对齐方式
DerivePointerAlignment: false
# 关闭格式化
DisableFormat:   false
# 删除访问修饰符后的所有空行
EmptyLineAfterAccessModifier: Never
# 仅当访问修饰符开始一个新的逻辑块时才添加空行
EmptyLineBeforeAccessModifier: Never
# 自动检测函数的调用和定义是否被格式为每行一个参数(Experimental)
ExperimentalAutoDetectBinPacking: false
# 自动补充namespace注释
FixNamespaceComments: false
# 需要被解读为foreach循环而不是函数调用的宏
ForEachMacros: ['RANGES_FOR', 'FOREACH']
IfMacros: ['IF']
# 多个#include块合并在一起并排序为一个
IncludeBlocks:   Merge
# 可以定义负数优先级从而保证某些#include永远在最前面
IncludeCategories:
  - Regex:           '^"(llvm|llvm-c|clang|clang-c)/'
    Priority:        2
    SortPriority:    0
    CaseSensitive:   false
  - Regex:           '^(<|"(gtest|gmock|isl|json)/)'
    Priority:        3
    SortPriority:    0
    CaseSensitive:   false
  - Regex:           '.*'
    Priority:        1
    SortPriority:    0
    CaseSensitive:   false
IncludeIsMainRegex: '(Test)?$'
IncludeIsMainSourceRegex: ''
# 缩进访问修饰符
IndentAccessModifiers: false
# 缩进case标签
IndentCaseLabels: false
# case 标签后面的块使用与 case 标签相同的缩进级别
IndentCaseBlocks: false
# 向后兼容缩进外部块
IndentExternBlock: AfterExternBlock
# 缩进goto标签。
IndentGotoLabels: false
# 缩进预处理器指令
IndentPPDirectives: BeforeHash
# 缩进模板中的requires子句
IndentRequires:  false
# 缩进宽度
IndentWidth: 4
# 函数返回类型换行时，缩进函数声明或函数定义的函数名
IndentWrappedFunctionNames: false
#InsertBraces: true
# 插入尾随逗号
InsertTrailingCommas: None
# 保留JavaScript字符串引号
JavaScriptQuotes: Leave
# 包装 JavaScript 导入/导出语句
JavaScriptWrapImports: true
# 保留在块开始处的空行
KeepEmptyLinesAtTheStartOfBlocks: false
# 相对于 lambda 签名对齐 lambda 主体
LambdaBodyIndentation: Signature
# 开始一个块的宏的正则表达式
MacroBlockBegin: ''
# 结束一个块的宏的正则表达式
MacroBlockEnd:   ''
# 连续空行的最大数量
MaxEmptyLinesToKeep: 1
# 命名空间的缩进
NamespaceIndentation: All
ObjCBinPackProtocolList: Auto
# 使用ObjC块时缩进宽度
ObjCBlockIndentWidth: 4
ObjCBreakBeforeNestedBlockParam: true
# 在ObjC的@property后添加一个空格
ObjCSpaceAfterProperty: false
# 在ObjC的protocol列表前添加一个空格
ObjCSpaceBeforeProtocolList: true
# 缩进预处理器语句的列数
PPIndentWidth:   -1
PenaltyBreakAssignment: 2
PenaltyBreakBeforeFirstCallParameter: 19
PenaltyBreakComment: 300
PenaltyBreakFirstLessLess: 120
PenaltyBreakString: 1000
PenaltyBreakTemplateDeclaration: 10
PenaltyExcessCharacter: 1000000
PenaltyReturnTypeOnItsOwnLine: 60
PenaltyIndentedWhitespace: 0
# 指针的对齐: Left, Right, Middle
PointerAlignment: Right
# 引用的对齐
ReferenceAlignment: Pointer
# 允许重新排版注释
ReflowComments:  true
#RemoveBracesLLVM: false
# 短命名空间跨越的最大展开行数
ShortNamespaceLines: 1
# 允许排序#include
SortIncludes:    CaseSensitive
# java静态导入放在非静态导入之前
SortJavaStaticImport: Before
# 对using声明排序
SortUsingDeclarations: true
# 在C风格类型转换后添加空格
SpaceAfterCStyleCast: false
# 在!后添加空格
SpaceAfterLogicalNot: false
# 在Template关键字后添加空格
SpaceAfterTemplateKeyword: true
# 不要确保指针限定符周围有空格
SpaceAroundPointerQualifiers: Default
# 在赋值运算符之前添加空格
SpaceBeforeAssignmentOperators: true
# 不在case冒号之前添加空格
SpaceBeforeCaseColon: false
# 不在C++11大括号列表之前添加空格
SpaceBeforeCpp11BracedList: false
# 在构造函数初始化器冒号之前添加空格
SpaceBeforeCtorInitializerColon: true
# 在继承冒号前添加空格
SpaceBeforeInheritanceColon: true
# 开圆括号之前添加一个空格
SpaceBeforeParens: ControlStatements
# 在基于范围的for循环冒号之前添加空格
SpaceBeforeRangeBasedForLoopColon: true
# 中括号前空格
SpaceBeforeSquareBrackets: false
# {}中间空格
SpaceInEmptyBlock: false
# 在空的圆括号中添加空格
SpaceInEmptyParentheses: false
# 在尾随的评论前添加的空格数(只适用于//)
SpacesBeforeTrailingComments: 2
# 在尖括号的<后和>前添加空格
SpacesInAngles:  true
# 在C风格类型转换的括号中添加空格
SpacesInCStyleCastParentheses: false
# 不在if/for/switch/while条件周围插入空格
SpacesInConditionalStatement: false
# 在容器(ObjC和JavaScript的数组和字典等)字面量中添加空格
SpacesInContainerLiterals: true
# 行注释开头允许有多少个空格。要禁用最大值，请将其设置为-1，除此之外，最大值优先于最小值
SpacesInLineCommentPrefix:
  Minimum:         1
  Maximum:         -1
# 在圆括号的(后和)前添加空格
SpacesInParentheses: false
# 在方括号的[后和]前添加空格，lamda表达式和未指明大小的数组的声明不受影响
SpacesInSquareBrackets: false
# 标准
Standard:        Auto
# 在语句前面被忽略的宏定义，就好像它们是一个属性一样
StatementAttributeLikeMacros:
  - Q_EMIT
# 应该被解释为完整语句的宏定义
StatementMacros:
  - Q_UNUSED
  - QT_REQUIRE_VERSION
# tab宽度
TabWidth:        4
# 使用\r\n换行替代\n
UseCRLF:         false
# 使用tab字符：ForIndentation——仅将制表符用于缩进
UseTab:          Never
# 对空格敏感的宏定义
WhitespaceSensitiveMacros:
  - STRINGIZE
  - PP_STRINGIZE
  - BOOST_PP_STRINGIZE
  - NS_SWIFT_NAME
  - CF_SWIFT_NAME
...
```

保存并关闭，至此，你已经完成了 vim 的配置。

## 运行 C++ 代码

你可以新建一个文件夹，运行命令：

```bash
mkdir -p Code && cd Code
```

这样你就新建并进入到了一个名为 Code 的文件夹，新建 test.cpp 文件：

```bash
vim test.cpp
```

输入一段没有格式化的代码：

```cpp
#include<bits/stdc++.h>
using namespace std;
int main()
{
int a,b;
cin>>a>>b;
cout<<a+b<<"Hello World!"<<endl;
return 0;
}
```

然后按下 `F4` 就会得到一段格式化好的代码：

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    cout << a + b << endl << "Hello World!" << endl;
    return 0;
}
```

按下 `F5`，就会编译并运行。

至此你就学会了用 vim 编译运行 C++ 代码。

## 参考内容

[WSL：Windows 与 Linux 的无缝对接](https://www.luogu.com.cn/article/zu2hqcj9)——@[NOI_Winner](https://www.luogu.com.cn/user/747900)。