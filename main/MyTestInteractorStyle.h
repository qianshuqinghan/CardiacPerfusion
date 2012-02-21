#ifndef MyTestInteractorStyle_H
#define MyTestInteractorStyle_H

#include "vtkImageViewer2.h"
#include "vtkInteractorStyleTrackballCamera.h"
#include "vtkCoordinate.h"
#include "vtkSmartPointer.h"
#include "vtkPolyData.h"

class MyTestInteractorStyle : public vtkInteractorStyleTrackballCamera
{
	public:
      static MyTestInteractorStyle* New();
      vtkTypeMacro(MyTestInteractorStyle, vtkInteractorStyleTrackballCamera);

	  MyTestInteractorStyle();
	  ~MyTestInteractorStyle();


	  void setImageViewer(vtkSmartPointer<vtkImageViewer2> viewer);

    private:
	  virtual void OnKeyPress();
	  virtual void OnMouseWheelForward();
	  virtual void OnMouseWheelBackward();
	  virtual void OnLeftButtonDown();
	  virtual void OnLeftButtonUp();
	  virtual void OnRightButtonDown();
	  virtual void OnRightButtonUp();
	  virtual void OnMiddleButtonDown();
	  virtual void OnMiddleButtonUp();
	  virtual void OnMouseMove();
	  //virtual void OnMouseClick();


	  void selectUserInteraction(); 
	  void setStartPoint(int* p);
	  void setEndPoint(int* p);

	  void goThroughVolume();
	  void paintRegion();
	  void windowLevel();

	  vtkSmartPointer<vtkImageViewer2> m_viewer;
	  vtkSmartPointer<vtkCoordinate> m_startPoint;
	  vtkSmartPointer<vtkCoordinate> m_endPoint;
	  vtkSmartPointer<vtkCoordinate> m_mouseMovement;
	  vtkSmartPointer<vtkPolyData> m_region;
	  vtkSmartPointer<vtkPoints> m_roiPoints;


	  bool m_leftMouseButtonDown;
	  bool m_rightMouseButtonDown;
	  bool m_middleMouseButtonDown;
	  bool m_painting;

};
#endif