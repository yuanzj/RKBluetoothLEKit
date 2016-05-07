#
# Be sure to run `pod lib lint RKBluetoothLEKit.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = "RKBluetoothLEKit"
  s.version          = "0.1.0"
  s.summary          = "车精灵中控蓝牙SDK"

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
车精灵中控蓝牙SDK
                       DESC

  s.homepage         = "https://github.com/yuanzj/RKBluetoothLEKit"
  # s.screenshots     = "www.example.com/screenshots_1", "www.example.com/screenshots_2"
  s.license          = 'MIT'
  s.author           = { "yuanzhijian" => "zhijian.yuan@rokyinfo.com" }
  s.source           = { :git => "https://github.com/yuanzj/RKBluetoothLEKit.git", :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '8.0'
  # s.source_files = 'RKBluetoothLEKit/Classes/**/*'
  # s.resource_bundles = {
  #   'RKBluetoothLEKit' => ['RKBluetoothLEKit/Assets/*.png']
  # }

  s.requires_arc = true
  s.preserve_paths = 'RKBluetoothLE_iOS.framework'
  s.public_header_files = '*.framework/Headers/*.h'
  s.vendored_frameworks = 'RKBluetoothLE_iOS.framework'

  s.dependency 'ReactiveCocoa'
  s.dependency 'CocoaSecurity'
end
