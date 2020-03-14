#include <forge.h>

class ExampleLayer : public forge::Layer
{
  public:
	ExampleLayer(): Layer("Example") {}
	void OnUpdate() override { FRG_INFO("ExampleLayer::Update"); }
	void OnEvent(forge::Event& event) override { FRG_INFO("{0}", event); }
};

class TerraGenApplication : public forge::Application
{
  public:
	TerraGenApplication() { PushLayer(new ExampleLayer()); }
	~TerraGenApplication() {}
};

forge::Application* forge::CreateApplication() { return new TerraGenApplication(); }
