#
# Be sure to run `pod lib lint RKBluetoothLEKit.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = "RKBluetoothLEKit"
  s.version          = "0.2.3"
  s.summary          = "车精灵中控蓝牙SDK"

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
车精灵中控蓝牙SDK,提供车辆操控、个性化、自检等功能。API调用模式使用了RAC
                       DESC

  s.homepage         = "https://github.com/yuanzj/RKBluetoothLEKit"
  # s.screenshots     = "www.example.com/screenshots_1", "www.example.com/screenshots_2"
  s.license          = 'MIT'
  s.author           = { "yuanzj" => "jswxyzj@qq.com" }
  s.source           = { :git => "https://github.com/yuanzj/RKBluetoothLEKit.git", :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '8.0'
  s.platform     = :ios, '8.0'
  s.requires_arc = true

  # s.source_files = 'RKBluetoothLEKit/Classes/**/*'
  
  # s.resource_bundles = {
  #   'RKBluetoothLEKit' => ['RKBluetoothLEKit/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  s.frameworks = 'Foundation', 'CoreBluetooth'
  s.dependency 'ReactiveCocoa', '~> 4.1.0'
  s.dependency 'CocoaSecurity', '~> 1.2.4'
  s.vendored_frameworks = 'RKBluetoothLEKit/*.{framework}'
  
end
