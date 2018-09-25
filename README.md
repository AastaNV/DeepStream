1. Flash JetPack 3.2 

2. Install DeepStream
-Get DeepStream_SDK_on_Jetson_1.5_pre-release.tbz2 from https://developer.nvidia.com/deepstream-jetson

tar xpvf DeepStream_SDK_on_Jetson_1.5_pre-release.tbz2
sudo tar xpvf deepstream_sdk_on_jetson.tbz2 -C /
sudo tar xpvf deepstream_sdk_on_jetson_models.tbz2 -C /
sudo ldconfig

3. Install sample
git clone 
cp -r DeepStream/configs/* ${HOME}/configs/
cp -r DeepStream/Model/* ${HOME}/Model
cp -r parser_detectnet/ ${HOME}
cd ${HOME}/parser_detectnet/
$ make

