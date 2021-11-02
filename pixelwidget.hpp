#ifndef _PIXEL_WIDGET_
#define _PIXEL_WIDGET_

#include <QtGui>
#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>
#include <QPainter>
#include <QLabel>
#include <QDesktopWidget>
#include <iostream>
#include <vector>
#include "RGBVal.hpp"
#include "ParameterisedLine.hpp"


class PixelWidget : public QWidget {
public:

  
  // set the number of pixels that the widget is meant to display
  PixelWidget
  (
   unsigned int n_horizontal, // the first integer determines the number of horizontal pixels 
   unsigned int n_vertical    // the second integer determines the number of vertical pixels
   );

  // sets a pixel at the specified RGBVal value; ignores non-existing pixels without warning
  void SetPixel
  ( 
   unsigned int  i_x, // horizontal pixel coordinate
   unsigned int  i_y, // vertical pixel coordinate
   const RGBVal& c    // RBGVal object for RGB values
    );

  // Use the body of this function to experiment with rendering algorithms
  void DefinePixelValues();

  void DrawLine(float x1, float y1, float x2, float y2, const RGBVal& colour1, const RGBVal& colour2);
  void DrawLinePerfect(float x1, float y1, float x2, float y2, bool debugInfo = false);

protected:

  virtual void paintEvent(QPaintEvent*);

private:

  std::vector<int> findIntegersInFloatRange(float x, float y);
  float findIntersection(const ParameterisedLine& line1, const ParameterisedLine& line2);


private:

  unsigned int _n_vertical;
  unsigned int _n_horizontal;

  std::vector<std::vector<RGBVal> > _vec_rects;
};

#endif

