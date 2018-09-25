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


#include "nvparsebbox.h"
#include <iostream>

/* detectnet */
void parse_bbox_custom_detectnet(DimsCHW outputDims, DimsCHW outputDimsBBOX,
    vector<cv::Rect> *rectList, int class_num, int batch_th, int net_width, int net_height,
    float *output_cov_buf,float *output_bbox_buf, float *classthreshold)
{
    int grid_x_ = outputDims.w();
    int grid_y_ = outputDims.h();
    int gridsize_ = grid_x_ * grid_y_;
    int gridoffset = outputDims.c() * outputDims.h() * outputDims.w() * batch_th;

    int cell_width  = net_width  / grid_x_;
    int cell_height = net_height / grid_y_;

    for (int c = 0; c < outputDims.c(); c++)
    {
        for (int h = 0; h < grid_y_; h++)
        {
            for (int w = 0; w < grid_x_; w++)
            {
                int i = w + h * grid_x_;

                if (output_cov_buf[gridoffset + c*gridsize_+i] >= classthreshold[c])
                {
                    float mx = w * cell_width;
                    float my = h * cell_height;

                    int bboxoffset = outputDimsBBOX.c() * outputDimsBBOX.h() * outputDimsBBOX.w() * batch_th;
                    int bboxsize = outputDimsBBOX.h() * outputDimsBBOX.w();
                    int j = w + h * grid_x_;
                    float x1 = output_bbox_buf[bboxoffset+(c*4+0)*bboxsize+j] + mx;
                    float y1 = output_bbox_buf[bboxoffset+(c*4+1)*bboxsize+j] + my;
                    float x2 = output_bbox_buf[bboxoffset+(c*4+2)*bboxsize+j] + mx;
                    float y2 = output_bbox_buf[bboxoffset+(c*4+3)*bboxsize+j] + my;

                    rectList[c].push_back(cv::Rect(x1, y1, x2-x1, y2-y1));
                }
            }
        }
    }
}
