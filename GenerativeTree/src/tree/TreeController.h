#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

// Blueadet Includes
#include "bluecadet/views/BaseView.h"
#include "bluecadet/views/ImageView.h"
#include "bluecadet/views/TouchView.h"

// Project Includes
#include "base\BaseTree.h"

namespace genApp {

	typedef std::shared_ptr<class TreeController> TreeControllerRef;

	class TreeController : public bluecadet::views::BaseView {

	public:

		TreeController();
		~TreeController();

		void	setup();

	protected:
		// Functions
		void	setupParams();

		// Views
		BaseTreeRef mBaseTree;

	};
}
