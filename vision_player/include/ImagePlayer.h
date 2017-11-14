//
// Created by lisa on 03.11.17.
//
#pragma once

#include "msl_ptgrey_camera/MSLPtGreyCamera.h"
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <SystemConfig.h>


class ImagePlayer
{


public:
    ImagePlayer();

    virtual ~ImagePlayer();

    string path;
    int nImages;
    void initialiseParameters();



private:

    supplementary::SystemConfig* sc;
};



