#include "MainController.h"

#include "cinder/Log.h"

#include "bluecadet/utils/ImageManager.h"
// TODO: Add video manager in 
//#include "bluecadet/utils/VideoManager.h"

#include "bluecadet/core/SettingsManager.h"
#include "bluecadet/core/ScreenLayout.h"

#include "bluecadet/views/AnimatedView.h"
#include "bluecadet/views/TextView.h"

#include "core/GenerativeTreeSettingsManager.h"
// TODO: Add CMS data manager
//#include "data/DataManager.h"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace bluecadet;
using namespace bluecadet::core;
using namespace bluecadet::views;
using namespace bluecadet::utils;

namespace genApp {

	MainController::MainController() : BaseView() {
	}

	MainController::~MainController() {
	}

	void MainController::setup() {

		// Load data
		// Add CMS data manager in
		//DataManager::getInstance()->loadAllData();
		ImageManager::getInstance()->loadAllFromDir(getAssetPath("images"));

		if (!GenerativeTreeSettingsManager::getInstance()->mDebugEnabled || GenerativeTreeSettingsManager::getInstance()->mVideosPreload) {
			const auto videoDir = getAssetPath(GenerativeTreeSettingsManager::getInstance()->mVideosAssetDir);
			// Add Video Manager in
			// VideoManager::getInstance()->loadAllFromDir(videoDir);
		}

		// Debugging
		setupParams();

		// Configure canvas
		setSize(ScreenLayout::getInstance()->getAppSize());

		// Setup Views
		mTreeController = make_shared<TreeController>();
		mTreeController->setup();
		addChild(mTreeController);
	}


	//==================================================
	// Setup helpers
	// 

	void MainController::setupParams() {

	}

}
