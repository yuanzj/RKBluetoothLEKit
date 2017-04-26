# RKBluetoothLEKit

[![CI Status](http://img.shields.io/travis/yuanzhijian/RKBluetoothLEKit.svg?style=flat)](https://travis-ci.org/yuanzhijian/RKBluetoothLEKit)
[![Version](https://img.shields.io/cocoapods/v/RKBluetoothLEKit.svg?style=flat)](http://cocoapods.org/pods/RKBluetoothLEKit)
[![License](https://img.shields.io/cocoapods/l/RKBluetoothLEKit.svg?style=flat)](http://cocoapods.org/pods/RKBluetoothLEKit)
[![Platform](https://img.shields.io/cocoapods/p/RKBluetoothLEKit.svg?style=flat)](http://cocoapods.org/pods/RKBluetoothLEKit)
## 概述
### 锐祺蓝牙iOS SDK V3.1.5
锐祺蓝牙iOS SDK是一套基于iOS8.0及以上版本设备的应用程序接口，不仅提供基本的上电、断电、设防、撤防、寻车、开启座桶遥控操作指令，还提供当前车况信息查询服务如总里程、剩余电量、车辆状态等。
在蓝牙连接成功的状态下会自动根据一定的策略进行数据上报充分保证服务器采集到的车辆信息为最新状态。

## 开发指南
### 简介
#### 什么是锐祺蓝牙iOS SDK？
RKBleSDK提供的功能如下：
- 遥控器（上电、断电、设防、撤防、寻车、开启座桶）
- 实时车况查询（状态、总里程、剩余电量、......）
- 故障查询
- 序列号、固件版本查询
- 参数配置（三色灯、来电及短信提醒、......）
- 车况信息上传

### 配置开发环境
自动配置.framework形式开发包（使用CocoaPods）
注：此种方式只支持导入全量包的SDK，包含锐祺蓝牙iOS SDK所有功能

1、前提：安装CocoaPods
在终端输入
```
sudo gem install cocoapods
```
如果安装成功，会有一个提示
```
Successfully installed cocoaPods
```
2、使用CocoaPods导入蓝牙 SDK
在当前工程文件（.xcodeproj）所在文件夹下，打开terminal
1.创建Podfile：
touch Podfile
2.编辑Podfile内容如下：

```
pod 'RKBluetoothLEKit', '~> 3.1.5'  #蓝牙 SDK
```

3.在Podfile所在的文件夹下输入命令：

```
pod install
```
（这个可能比较慢，请耐心等待……）
### 遥控器
#### 上电
调用代码如下：

```
[[RK4103APIServiceImpl powerOn:ueSN] subscribeNext:^(RemoteControlResult *response){

} error:^(NSError *error){

}];
```


#### 断电
调用代码如下：

```
[[RK4103APIServiceImpl powerOff:ueSN] subscribeNext:^(RemoteControlResult *response){

} error:^(NSError *error){

}];
```

#### 寻车
调用代码如下：

```
[[RK4103APIServiceImpl find:ueSN] subscribeNext:^(RemoteControlResult *response){

} error:^(NSError *error){
NSLog(@"%@",error);
}];
```

### 车况查询
调用代码如下：

```
[[[RK4103APIServiceImpl getVehicleStatus:ueSN] deliverOn:[RACScheduler mainThreadScheduler]] subscribeNext:^(VehicleStatus *response){
[[[UIAlertView alloc] initWithTitle:nil message:[response description] delegate:nil cancelButtonTitle:@"确认" otherButtonTitles:nil, nil] show];
} error:^(NSError *error){

}];
```

### 故障查询
调用代码如下：

```
[[[RK4103APIServiceImpl getFault:ueSN] deliverOn:[RACScheduler mainThreadScheduler]]  subscribeNext:^(Fault_Rk4103 *response){
[[[UIAlertView alloc] initWithTitle:nil message:[response description] delegate:nil cancelButtonTitle:@"确认" otherButtonTitles:nil, nil] show];
} error:^(NSError *error){

}];
```

### 序列号、固件版本查询
调用代码如下：

```
[[[RK4103APIServiceImpl getDeviceVersion:ueSN paramter:VERSION_TYPE_ECU]deliverOn:[RACScheduler mainThreadScheduler]] subscribeNext:^(YadeaParamter *response){
NSLog(@"%@",[response description]);

[[[UIAlertView alloc] initWithTitle:nil message:[response description] delegate:nil cancelButtonTitle:@"确认" otherButtonTitles:nil, nil] show];

} error:^(NSError *error){
NSLog(@"%@",error);
}];
```

### 参数配置
调用代码如下：

```
YadeaParamter *mYadeaParamter       = [[YadeaParamter alloc] init];
mYadeaParamter.colorfulLight = 0x0000ff;
mYadeaParamter.autoCloseLight = 30;
mYadeaParamter.startTime = @"17:00";
mYadeaParamter.endTime = @"20:00";
mYadeaParamter.gears = 1;
[[[RK4103APIServiceImpl setCustomParameter:ueSN parameter :mYadeaParamter] deliverOn:[RACScheduler mainThreadScheduler]] subscribeNext:^(ConfigResult *response){

[[[UIAlertView alloc] initWithTitle:nil message:[NSString stringWithFormat:@"success:%d",response.success] delegate:nil cancelButtonTitle:@"确认" otherButtonTitles:nil, nil] show];
} error:^(NSError *error){

[[[UIAlertView alloc] initWithTitle:nil message:[NSString stringWithFormat:@"error:%@",[error localizedDescription]] delegate:nil cancelButtonTitle:@"确认" otherButtonTitles:nil, nil] show];
}];
```


### 车况信息上传
#### 简介
蓝牙连接成功后SDK会监听车辆信息的变化，在发现有数据变化后立即上报到后台服务器。 数据上报的最快频率支持可配置模式，确保在频繁变化后不对服务器造成太高的负载。
此项功能SDK内部自动完成，第三方无需主动调用相关接口。

## 更新日志

## 类参考
详情见API doc 文档
## 相关下载
[锐祺蓝牙iOS SDK 调试Demo下载地址](https://github.com/yuanzj/RKBluetoothLEKit)

## Author

yuanzhijian, zhijian.yuan@rokyinfo.com

## License

RKBluetoothLEKit is available under the MIT license. See the LICENSE file for more info.
