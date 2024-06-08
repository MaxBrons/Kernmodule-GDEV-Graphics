#include "KMG.h"
#include "ExampleLayer.h"

class ExampleApp : public KMG::Application
{
public:
	ExampleApp(const KMG::ApplicationSettings& settings) : KMG::Application(settings)
	{
		m_Layers.push_back(new ExampleLayer());
	}
	virtual ~ExampleApp() = default;
};

int main()
{
	auto* app = new ExampleApp({ "Graphics Example" });
	app->Run();

	delete app;
}