#pragma once
#include <iostream>
#include <etna/Sampler.hpp>
#include <etna/GlobalContext.hpp>
#include <etna/Window.hpp>
#include <etna/PerFrameCmdMgr.hpp>
#include <etna/ComputePipeline.hpp>
#include <etna/Image.hpp>

#include "wsi/OsWindowingManager.hpp"

struct uniform_params
{
      uint resolution_x;
      uint resolution_y;
};

class App
{
public:
  App();
  ~App();

  void run();

private:
  void drawFrame();

private:
  OsWindowingManager windowing;
  std::unique_ptr<OsWindow> osWindow;

  etna::ComputePipeline pipeline;
  etna::Image image;
  etna::Sampler defaultSampler;

  glm::uvec2 resolution;
  bool useVsync;

  std::unique_ptr<etna::Window> vkWindow;
  std::unique_ptr<etna::PerFrameCmdMgr> commandManager;
  uniform_params params;
};
