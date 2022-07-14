# 单目3d

- 经典论文，开山之作，deep3dbox
- 最近几年发展迅速，比如M3D-RPN,monopair, monoGRNet,rtmm3d, km3d,monoflex, monoEF,dd3d等
- ...

## 前期知识
- 图像坐标系、相机坐标系、世界坐标系的转换
- lidar坐标系、map坐标系、vehicle坐标系转换
- ...
## 数据认识
- 单目3d数据标注
- 怎么定义grouth让标注公司标注
- 给标注公司标注需要注意的坑
- ...      
## 模型训练
- ...
## pytorch->onnx
- 一些常见支持的op正常转即可
- 不支持的op怎么办，比如说DCN卷积、比如一些ScatterND，NoZero等操作...
- 把单目3d pytorch模型转为支持op的onnx模型、trt模型
- ...
## 单目3d模型部署
- ...
## 单目3d模型优化
- 速度优化
- 显存优化
- ...
## 后续换成其他单目3d模型给出的建议，需要着重解决的问题
- 比如怎样让单目3d感知进行量产
- ...

  
  
