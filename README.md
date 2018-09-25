# 1. Flash JetPack 3.2
- Get JetPack 3.2 from https://developer.nvidia.com/embedded/jetpack-3_2_1
</br>
</br>

# 2. Install DeepStream
- Get DeepStream_SDK_on_Jetson_1.5_pre-release.tbz2 from https://developer.nvidia.com/deepstream-jetson
</br>

'''C
$ tar xpvf DeepStream_SDK_on_Jetson_1.5_pre-release.tbz2
$ sudo tar xpvf deepstream_sdk_on_jetson.tbz2 -C /
$ sudo tar xpvf deepstream_sdk_on_jetson_models.tbz2 -C /
$ sudo ldconfig
'''

</br>
</br>

# 3. Install sample

'''C
$ git clone https://github.com/AastaNV/DeepStream.git
$ cp -r DeepStream/configs/* ${HOME}/configs/
$ cp -r DeepStream/Model/* ${HOME}/Model
$ cp -r parser_detectnet/ ${HOME}
$ cd ${HOME}/parser_detectnet/
$ make
'''

</br>
</br>

# 4. Launch sample

'''C
$  nvgstiva-app -c ${HOME}/configs/DetectNet.txt -i /home/nvidia/DeepStream/Meeting_1212_cut.h264
'''
