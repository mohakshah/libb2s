# libb2s
[![CI Status](http://img.shields.io/travis/mohakshah/libb2s.svg?style=flat)](https://travis-ci.org/mohakshah/libb2s)
[![Version](https://img.shields.io/cocoapods/v/libb2s.svg?style=flat)](http://cocoapods.org/pods/libb2s)
[![License](https://img.shields.io/cocoapods/l/libb2s.svg?style=flat)](http://cocoapods.org/pods/libb2s)
[![Platform](https://img.shields.io/cocoapods/p/libb2s.svg?style=flat)](http://cocoapods.org/pods/libb2s)

libb2s is a stripped down version of [libb2](https://github.com/BLAKE2/libb2)
that only contains the non-optimized reference implementation of BLAKE2s.
This version was created as a simple means to use BLAKE2s in iOS.
Although, it has also been tested to work well with macOS(clang) and desktop linux(gcc).

## Installation

### make
For a conventional installation, you can simply use the following commands:

```sh
make
make install
```

To change the installation prefix from the default /usr/local, use

```sh
make
make install --prefix=/something/else
```

To use the library, include `blake2s.h` in your source file and link with -lb2s.

### CocoaPods
libb2s is also available through [CocoaPods](http://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod 'libb2s', '~>1.0'
```

## License

libb2s is available under the CC0 license. See the LICENSE file for more info.
