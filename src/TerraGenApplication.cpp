#include <forge.h>

class ExampleLayer : public forge::Layer
{
  public:
	ExampleLayer(): Layer("Example") {}

	inline void OnUpdate() override
	{
		// FRG_INFO("A: {0}", forge::Input::IsKeyPressed(FRG_KEY_A));
	}

	inline void OnEvent(forge::Event& event) override
	{
		// FRG_INFO("{0}", event);
	}
};

class TerraGenApplication : public forge::Application
{
  public:
	TerraGenApplication() { PushLayer(new ExampleLayer()); }

	~TerraGenApplication() override {}
};

forge::Application* forge::CreateApplication()
{
	return new TerraGenApplication();
}
