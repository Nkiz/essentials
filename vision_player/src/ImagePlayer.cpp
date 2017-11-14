//
// Created by lisa on 03.11.17.
//

#include "ImagePlayer.h"

using std::endl;
using std::cout;
using namespace cv;

ImagePlayer::ImagePlayer()
{
    this->sc = supplementary::SystemConfig::getInstance();
    this->initialiseParameters();
}

ImagePlayer::~ImagePlayer()
{}


const cv::String WINDOWNAME = "ImagePreview";

void ImagePlayer::initialiseParameters() {

    this->nImages = (*this->sc)["Vision2"]->get<int>("Vision2.Recorder.maxImages", NULL);
    this->path = (*this->sc)["Vision2"]->get<string>("Vision2.Recorder.path", NULL);
}



int main(int argc, char **argv)
{

        ImagePlayer ip;
        namedWindow(WINDOWNAME, WINDOW_NORMAL);
        resizeWindow(WINDOWNAME, 800, 600);


        int frame = 0;
        while (true)
        {
            if (frame == 0)
            {
                frame = 1;
            }
            string name = ip.path;
            name.append(to_string(frame));
            name.append(".raw");
            if (++frame == ip.nImages)
            {
                frame = 1;
            }

            cout << name << endl;
            std::ifstream fin(name, std::ios::binary);


            fin.seekg(0, std::ios::end);
            int length = fin.tellg();
            fin.seekg(0, std::ios::beg);
            char *buffer = new char[length];
            fin.read(buffer, length);
            vector<uchar> src_vec(buffer, buffer + length);

//            cout << "read image finish! len = " << length << endl;

            Mat d_img = Mat(960,1280,CV_8UC1,buffer,1280);
//            Mat d_img = imdecode(img, CV_LOAD_IMAGE_GRAYSCALE);
            cvtColor(d_img, d_img, CV_BayerGB2RGB);
            sleep(0.1);
//            cout << d_img.cols << ", "
//                 << d_img.rows << endl;

            imshow("ImagePreview", d_img);

            cvWaitKey(1);
        }

    return 0;

}
