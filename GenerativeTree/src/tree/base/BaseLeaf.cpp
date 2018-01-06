#include "BaseLeaf.h"

#include "cinder/Log.h"

#include "bluecadet/utils/ImageManager.h"
#include "bluecadet/core/SettingsManager.h"
#include "bluecadet/core/ScreenLayout.h"

#include "bluecadet/views/AnimatedView.h"
#include "bluecadet/views/TextView.h"

#include "../../core/GenerativeTreeSettingsManager.h"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace bluecadet;
using namespace bluecadet::core;
using namespace bluecadet::views;
using namespace bluecadet::utils;

namespace genApp {

	BaseLeaf::BaseLeaf() : BaseView() {
	}

	BaseLeaf::~BaseLeaf() {
	}

	void BaseLeaf::setup() {
		// Configure canvas
		setSize(vec2(50));
		setBackgroundColor(ColorA(0, 0.8, 0.2, 0.4));
		setTransformOrigin(vec2(getWidth()/2, 0));

		// Setup Views

	}


	//==================================================
	// Setup helpers
	// 

	void BaseLeaf::setupParams() {

	}

}
