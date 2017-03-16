# libb2s

libb2s is a stripped down version of [libb2](https://github.com/BLAKE2/libb2)
that only contains the non-optimised reference implementation of BLAKE2s.
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
pod 'libb2s'
```

## License

libb2s is available under the CC0 license. See the LICENSE file for more info.
