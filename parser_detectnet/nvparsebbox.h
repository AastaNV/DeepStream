/**
 * Copyright (c) 2018, NVIDIA CORPORATION.  All rights reserved.
 *
 * NVIDIA Corporation and its licensors retain all intellectual property
 * and proprietary rights in and to this software, related documentation
 * and any modifications thereto.  Any use, reproduction, disclosure or
 * distribution of this software and related documentation without an express
 * license agreement from NVIDIA Corporation is strictly prohibited.
 *
 */

#ifndef _NVPARSEBBOX_H_
#define _NVPARSEBBOX_H_

#include "NvInfer.h"
#include <opencv2/core/core.hpp>

using namespace std;
using namespace nvinfer1;


#ifdef __cplusplus
extern "C"
{
#endif

void parse_bbox_custom_detectnet(DimsCHW outputDims, DimsCHW outputDimsBBOX,
        vector<cv::Rect> *rectList, int class_num, int batch_th, int net_width, int net_height,
        float *output_cov_buf,float *output_bbox_buf, float *classthreshold);

#ifdef __cplusplus
}
#endif

#endif
