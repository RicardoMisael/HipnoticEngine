#pragma once
#include "Prerequisites.h"
#include "Window.h"
#include "Device.h"
#include "DeviceContext.h"
#include "Swapchain.h"
#include "Texture.h"
#include "RenderTargetView.h"
#include "DepthStencilView.h"
#include "Viewport.h"
#include "ShaderProgram.h"
#include "MeshComponent.h"
#include "Buffer.h"
#include "SamplerState.h"
#include "UserInterface.h"

class
  BaseApp {
public:
  /**
   * @brief Constructor y destructor
   */
  BaseApp() = default;
  ~BaseApp() = default;

  /**
   * @brief Inicializa la aplicación con los recursos encesarios
   */
  HRESULT
  init();

  /**
   * @brief Actualiza la alicación en cada frame
   */
  void
  update();

  /**
   * @brief Renderiza el elemento
   */
  void
  render();

  /**
   * @brief Libera recursos y elementos antes de salir.
   */
  void
  destroy();

  /**
   * @brief Le hace resize a la ventana para que no se defigure al cambiar el tamaño
   */
  HRESULT
  ResizeWindow(HWND hWnd, LPARAM lParam);

  /**
  * @brief Maneja los inputs de la aplicaicón.
  */
  void
  inputActionMap(float deltaTime);

  /**
  * @brief Actualiza la matriz vista de la cámara
  */
  void
  UpdateCamera();

  /**
  * @brief Corre la aplicación
  */
  void
  RotateCamera(int mouseX, int mouseY);

  /**
   * @brief Ejecuta la aplicación
   */
  int
  run(HINSTANCE hInstance,
      HINSTANCE hPrevInstance,
      LPWSTR lpCmdLine,
      int nCmdShow,
      WNDPROC wndproc);

private:
  Window                              m_window;
  Device                              m_device;
  DeviceContext                       m_deviceContext;
  SwapChain                           m_swapchain;
  Texture                             m_backBuffer;
  Texture                             m_depthStencil;
  RenderTargetView                    m_renderTargetView;
  DepthStencilView                    m_depthStencilView;
  Viewport                            m_viewport;
  ShaderProgram                       m_shaderProgram;
  SamplerState                        m_samplerState;
  Buffer                              m_vertexBuffer;
  Buffer                              m_indexBuffer;
  Buffer                              m_neverChanges;
  Buffer                              m_changeOnResize;
  Buffer                              m_changesEveryFrame;
  Texture                             m_textureRV;
  UserInterface                       m_userInterface;
  MeshComponent                       MC;

  XMMATRIX                            m_modelMtrix;
  XMMATRIX                            m_View;
  XMMATRIX                            m_Projection;

  Camera                              m_camera;
  CBChangesEveryFrame                 cb;
  CBNeverChanges                      cbNeverChanges;
  CBChangeOnResize                    cbChangesOnResize;  

public:
  XMFLOAT3 position;
  XMFLOAT3 rotation;
  XMFLOAT3 scale;

  XMFLOAT4                            m_vMeshColor{ 0.7f, 0.7f, 0.7f, 1.0 };
  bool keys[256] = { false };
  int lastX;
  int lastY;
  float sensitivity = 0.01f;
  bool mouseLeftDown = false;
};