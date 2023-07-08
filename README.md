## Build program

```
cmake -B build -G Ninja
ninja -C build

or

cmake -B build
cmake --build build
```

##一些知识点

* 设定文件时使用file(),不要使用set file_resources类似的

GLOB不允许使用嵌套目录
GLOB_RECURSE允许使用嵌套，这点从recurse这个名字也能看出

* 加了CONFIGURE__DEPENDS这个选项的意义

不加的话创建新文件[test](src/test/CMakeLists.txt)里面的source源不会自动更新