#ifndef OPENGLCONTROLLER_H
#define OPENGLCONTROLLER_H

#include <QObject>
#include <QOpenGLWidget>
#include <QOpenGLExtraFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QTimer>
#include <QMatrix4x4>
#include <QSurfaceFormat>
#include "engine.h"
#include "shader.h"
#include "camera.h"
class OpenGLController : public QOpenGLWidget, protected QOpenGLExtraFunctions
{
  Q_OBJECT
public:
  using QOpenGLWidget::QOpenGLWidget;
  ~OpenGLController();
  struct glDrawArraysConfig {
    bool Points = false;
    bool Lines = true;
    bool Triangles = true;
    bool Triangles_strip = false;
    float Point_size = 1;
    float Line_width = 1;
    bool roundCircle = false;
    bool dashedLines = false;

  };
  struct cameraConfig {
    Camera::ViewMode viewMode = Camera::Perspective;
    Camera::CameraMode Mode = Camera::Free;
    QVector3D FocusPoint = QVector3D(0,0,0);
    QVector3D Position = QVector3D(0,0,0);
    QVector3D Orientation = QVector3D(0,0,1);
    QVector2D zRange = QVector2D(0.1, 10);
    float FOV = 60;
  };
  Camera * camera = nullptr;
  QColor FragmentColor = QColor(255,255,255);
  QColor LineColor = QColor(255,255,255);
  QColor DotColor = QColor(255,255,255);
  QColor BackColor = QColor(0,0,0);
  glDrawArraysConfig drawArrConf;
  cameraConfig cameraConf;
  void startScreenCapture(int FPS);
  std::vector<QImage> stopScreenCapture();
public slots:
  void setDrawArrConfig(struct glDrawArraysConfig config);
  void setCameraConfig(struct cameraConfig config);
  void importObjFile(QString filename);
  void setLineWidth(float width);
  void setScale(float scale);
  void setTranslation(QVector3D translation);
  void setRotation(QVector3D rotation);
  std::vector<QImage> getScreencast();
signals:

  void importComleted(long int vertN, long int edgesN, QString filename);
  void FOVChanged();
  void zNearChanged();
  void zFarChanged();

protected:
  void mousePressEvent(QMouseEvent *e) override;
  void mouseMoveEvent(QMouseEvent *e) override;
  void mouseReleaseEvent(QMouseEvent *e) override;
  void wheelEvent(QWheelEvent *e) override;
  void keyPressEvent(QKeyEvent *e) override;
  void keyReleaseEvent(QKeyEvent *e) override;

  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;
private slots:
  void capture();
private:

  void calcSizes(int w, int h);
  QPoint mPos = QPoint(0,0);

  QTimer captureTimer;
  bool LMB_pressed = false;
  bool RMB_pressed = false;

  QString filename;
  QVector3D rotationVec = QVector3D(0,0,0);
  QVector3D translationVec = QVector3D(0,0,0);

  int vw = 0, vh = 0, ratio = 0;
  float scale = 1;
  int width_line = 1;

  std::vector<QImage> captureBuffer;
  QSize gifResolution = QSize(640, 480);
  int gifFps = 10;
  int gifLength = 5;

  Shader* program = nullptr;
  Engine *geometries = nullptr;
  void initShaders();

  void setColorUniform(int id, QColor in);
  void setPointUniform(bool circle, float size);
  void setLineDash(bool on);
};

#endif // OPENGLCONTROLLER_H
