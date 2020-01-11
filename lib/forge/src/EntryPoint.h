#pragma once

//#ifdef FRG_PLATFORM_WINDOWS

extern forge::Application *forge::CreateApplication();

int main(int argc, char **argv) {

  forge::Log::Init();
  int a = 5;
  FRG_CORE_WARN("Initalizing Application");
  FRG_INFO("Hello From client, Var={0}", a);

  forge::Application *app = forge::CreateApplication();

  app->Run();

  delete app;

  return 0;
}

//#endif