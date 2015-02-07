//
//  ITheme.cpp
//  G-Ear core
//
//  Created by Zsolt Szatmári on 7/29/13.
//  Copyright (c) 2013 Treasure Box. All rights reserved.
//

#include "ITheme.h"
#include "NamedImage.h"
#include "Tinter.h"
#include "IApp.h"
#include "themeManager.h"

namespace Gui {
    
#define method ITheme:: 
    
    method ~ITheme()
    {
    }

    TextAttributes method navigationTextActive() const
    {
    	auto attribs = navigationText();
    	attribs.setColor(textHighlightColor());
    	return attribs;
    }
    
    shared_ptr<IPaintable> method ratingIcon(int rating) const
    {
        if (rating == 5) {
            return Tinter::tintWithColor(shared_ptr<IPaintable>(new NamedImage("thumbsup")), selected());
        } else if (rating == 1) {
            return Tinter::tintWithColor(shared_ptr<IPaintable>(new NamedImage("thumbsdown")), selected());
            //return shared_ptr<IPaintable>(new NamedImage("thumbsdown-selected"));
        } else {
            return Tinter::tintWithColor(shared_ptr<IPaintable>(new NamedImage("thumbsup")), gray());
        }
    }
    
    TextAttributes method miniplayerSubSubtitleText() const
    {
        auto subtitle = miniplayerSubtitleText();
        auto listsubsub = listSubSubtitleText();
        
        subtitle.setColor(listsubsub.color());
        return subtitle;
    }

	ITheme::SliderLook method volumeSlider() const
	{
		return seekSlider();
	}

    class NoArtImage : public NamedImage
    {
    public:
        NoArtImage() : 
            NamedImage("")
        {
        }

        virtual string imageName() const
        {
            return Gear::IApp::instance()->themeManager()->current()->noArtName();
        }
    };

    shared_ptr<IPaintable> method noArt()
    {
        static shared_ptr<IPaintable> ret(new NoArtImage());
        return ret;
    }

    string method noArtName() const
    {
        return "noart";
    }

    const Style & method style() const
    {
        return _style;
    }
}
