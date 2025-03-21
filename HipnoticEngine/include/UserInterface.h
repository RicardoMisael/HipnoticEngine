#pragma once
#include "Prerequisites.h"

class Window;
class Device;
class DeviceContext;

class
UserInterface {
public:
  UserInterface() = default;
  ~UserInterface() = default;

  /**
   * @brief Inicializa los elementos de la interfaz de usuario.
   * @param window Puntero a la ventana en la que se mostrará la interfaz.
   * @param device Dispositivo gráfico utilizado para la renderización.
   * @param deviceContext Contexto del dispositivo para las operaciones gráficas.
   */
  void
  init(void* window,
       ID3D11Device* device,
       ID3D11DeviceContext* deviceContext);

  /**
   * @brief Actualiza el estado de la interfaz de usuario.
   */
  void
  update();

  /**
   * @brief Renderiza la interfaz de usuario en la ventana.
   */
  void
  render();

  /**
   * @brief Libera los recursos
   */
  void
  destroy();

  /**
   * @brief Añade un estilo basado en Natanael Cano
   */
  void
  NataStyle();

  /**
   * @brief Inspector con los componentes del Transform
   */
  void
  Inspector();

private:
};