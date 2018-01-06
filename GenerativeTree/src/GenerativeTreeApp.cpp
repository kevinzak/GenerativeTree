#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "bluecadet/core/BaseApp.h"
#include "bluecadet/views/TouchView.h"

// Fonts
#include "bluecadet/text/FontManager.h"
#include "bluecadet/text/StyleManager.h"
#include "bluecadet/text/StyledTextParser.h"

#include "MainController.h"
#include "core/GenerativeTreeSettingsManager.h"

using namespace ci;
using namespace ci::app;
using namespace std;

using namespace bluecadet::core;
using namespace bluecadet::views;
using namespace bluecadet::text;
using namespace bluecadet::touch;
using namespace genApp;

class GenerativeTreeApp : public BaseApp {
public:
	static void prepareSettings(ci::app::App::Settings* settings);
	void setup() override;
	void update() override;
	void draw() override;
private:
	MainControllerRef mMainController = nullptr;
};

void GenerativeTreeApp::prepareSettings(ci::app::App::Settings* settings) {
	SettingsManager::setInstance(GenerativeTreeSettingsManager::getInstance());
	SettingsManager::getInstance()->setup(settings, ci::app::getAssetPath("settings.json"), [](SettingsManager * manager) {});
}
void GenerativeTreeApp::setup()
{
	BaseApp::setup();
	BaseApp::addTouchSimulatorParams();

	FontManager::getInstance()->setup(getAssetPath("fonts/fonts.json"));
	StyleManager::getInstance()->setup(getAssetPath("fonts/styles.json"), "styles");
	StyledTextParser::getInstance()->setDefaultOptions(
		StyledTextParser::OptionFlags::INVERT_NESTED_ITALICS |
		StyledTextParser::OptionFlags::TRIM_WHITESPACE |
		StyledTextParser::OptionFlags::TRIM_LEADING_BREAKS |
		StyledTextParser::OptionFlags::TRIM_TRAILING_BREAKS
	);
	mMainController = MainControllerRef(new MainController());
	mMainController->setup();
	getRootView()->addChild(mMainController);

}

void GenerativeTreeApp::update()
{
	BaseApp::update();
}

void GenerativeTreeApp::draw()
{
	BaseApp::draw();
}

CINDER_APP(GenerativeTreeApp, RendererGl(RendererGl::Options().msaa(4).stencil(true)), GenerativeTreeApp::prepareSettings);
