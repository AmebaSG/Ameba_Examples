# MQTT协议

此示例是Arduino包附带的原始“mqtt basic”示例的变体。在这个例子中，简单的无源组件被用来帮助演示MQTT协议的双向通信的能力，因其在响应速度和较轻量上的优势，MQTT协议在现代物联网应用中被广泛使用。

在这个演示中，安卓平板电脑是一个MQTT客户端，Ameba RTL8195开发板作另一个与android平板电脑通信的MQTT客户机。在进行下一步之前，两个客户机必须连接到相同的MQTT服务器，您可以选择按照http://www.steves-internet-guide.com/mqtt-hosting-brokers-and-servers/ 的在线指南设置自己的MQTT服务器，或者使用 test.mosquitto.org 上的免费服务器。

通过从安卓设备发送一个“1”到Ameba板，会点亮与Ameba连接的LED，而发送一个“0”将会关闭LED。您可以随时按下与Ameba板连接的按钮，查询LED状态并将其转发给您的安卓平板电脑。这个设计模拟了物联网产品在智能家居中的实际应用，并且非常容易实现。如果您对自己动手感兴趣，请参阅我们的GitHub页面了解更多细节。

# 软件
1. 请使用arduino IDE将“MQTT_BASIC.ino”上传到您的Ameba RTL8195板上
2. 请在您的智能设备(android/iOS)上安装一个MQTT客户端应用程序

# 硬件
列表:
1. 发光二极管  x1
2. 按钮       x1
3. 面包板     x1
4. 电线       x4
5. 220欧姆电阻 x2
6. 安卓/iOS设备x1
7. 支架(可选)  x1
