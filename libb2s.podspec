#
# Be sure to run `pod lib lint libb2.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'libb2s'
  s.version          = '1.0.2'
  s.summary          = 'A portable C library providing the BLAKE2s hashing function'

  s.description      = <<-DESC
libb2s is a stripped down version of [libb2](https://github.com/BLAKE2/libb2)
that only contains the non-optimised reference implementation of BLAKE2s.
This version was created as a simple means to use the BLAKE2s in iOS.
Although, it has been tested to work well with macOS(clang) and desktop linux(gcc)
as well.
                       DESC

  s.homepage         = 'https://github.com/mohakshah/libb2s'
  s.license          = { :type => 'CC0', :file => 'LICENSE' }
  s.author           = { 'Mohak Shah' => 'mohak@mohakshah.in' }
  s.source           = { :git => 'https://github.com/mohakshah/libb2s.git', :tag => s.version.to_s }

  s.ios.deployment_target = ""
  s.osx.deployment_target = ""
  s.watchos.deployment_target = ""
  s.tvos.deployment_target = ""

  s.source_files = 'src/*.{c,h}'
  s.pod_target_xcconfig = { 'HEADER_SEARCH_PATHS' => '"$(PODS_TARGET_SRCROOT)/libb2s/src/"' }

  s.public_header_files = 'src/blake2s.h'
end
