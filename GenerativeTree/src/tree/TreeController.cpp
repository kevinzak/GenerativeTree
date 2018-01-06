#include "TreeController.h"

#include "cinder/Log.h"

#include "bluecadet/utils/ImageManager.h"
#include "bluecadet/core/SettingsManager.h"
#include "bluecadet/core/ScreenLayout.h"

#include "bluecadet/views/AnimatedView.h"
#include "bluecadet/views/TextView.h"

#include "../core/GenerativeTreeSettingsManager.h"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace bluecadet;
using namespace bluecadet::core;
using namespace bluecadet::views;
using namespace bluecadet::utils;

namespace genApp {

	TreeController::TreeController() : BaseView() {
	}

	TreeController::~TreeController() {
	}

	void TreeController::setup() {
		// Configure canvas
		setSize(ScreenLayout::getInstance()->getAppSize());
		setBackgroundColor(Color(76.0f / 255.0f, 134.0f / 255.0f, 211.0f / 255.0f));

		// Setup Views
		mBaseTree = make_shared<BaseTree>();
		mBaseTree->setup();
		mBaseTree->setPosition(vec2(getWidth() * 0.5f, 0));
		addChild(mBaseTree);

	}


	//==================================================
	// Setup helpers
	// 

	void TreeController::setupParams() {

	}

}
