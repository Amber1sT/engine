#pragma once
#include "UIImage.h"

namespace star
{
	class UIButton;

	class UISlider : public UIImage
	{
	public:
		UISlider(
			const tstring & name,
			const tstring & file,
			const tstring & file_bg,
			bool sliderIsHorizontal,
			bool spritesheetIsVertical = true
			);
		virtual ~UISlider();

		virtual void AfterInitialized();
		virtual void Update(const Context & context);

		void SetPercent(float32 percent);
		float32 GetPercent() const;

		void SetSelectedCallback(
			const std::function<void(float32)> & callback
			);

		void SetDownCallback(
			const std::function<void(float32)> & callback
			);

	protected:
		void SetPositionAccordingToPercent();

		bool m_SliderIsHorizontal;
		bool m_SliderIsDown;

		UIButton * m_pSlider;
		float32 m_Percent;

		std::function<void(float32)>
			m_SelectCallback,
			m_DownCallback;

	private:
		UISlider(const UISlider &);
		UISlider(UISlider &&);
		UISlider & operator=(const UISlider &);
		UISlider & operator=(UISlider &&);
	};
}