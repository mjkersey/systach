import QtQuick 1.1
import org.kde.plasma.core 0.1 as PlasmaCore
import "../code/systach-main.js" as JS

Rectangle {
  id: gaugeMain
  anchors.fill: parent
  smooth: true
  color: "transparent"
  
  property int gIconColor: 4
  
  Component.onCompleted: { 
    JS.loadGlass();
    JS.loadIcon();
    JS.configureEngine();
    console.log(gFontColor);
    gaugeTest.running = true
  }
  
  function updateGauge(gData) {
    gValue = parseFloat(eval('gData.' + gField));
    gDisplay = gValue / gDivisor;
    
    if (qMessages.text != "") {
	qMessages.text = "";
    }
  
    if(!isNaN(gValue)){
      
      if ( gMinRange == 0 && gMaxRange == 0 ) {
	if ( gData.min != undefined && gData.max != undefined ) {
	  gMinRange = gData.min;
	  gMaxRange = gData.max;
	}
      }
      
      if (gValue < gMinRange) {
	gValue = gMinRange;
	if (gAuto == true) {
	  qMessages.text = "Adjusting range...";
	  setAuto(gValue, gMaxRange);
	}
      }

      if (gValue > gMaxRange) {
	gValue = gMaxRange;
	if (gAuto == true) {
	  qMessages.text = "Adjusting range...";
	  setAuto(gMinRange, gValue);
	}	  
      }
      
      var gLimits = iniSettings.angleLimits;
      var gRange = parseInt(gLimits.max) - parseInt(gLimits.min);
      var vRange = gMaxRange - gMinRange;
      var gPercentage = (gValue - gMinRange) / vRange;
      var gAngle = parseInt(gLimits.min) + (Math.round(gRange * gPercentage));
      
      if (gRaw) {
 	if (gLabel == "") {
 	  if (!gData.name == '') {
	    dLabel = gData.name; // Context property override not allowed
	  }
	} else {
	  dLabel = gLabel;
	}
	if (!gData.units == '') { 
	  gUnits = gData.units;
	}

	gaugeLabel.text = "<center>" + dLabel + "<br>" + gDisplay.toFixed(gPrecision) + " " + gUnits + "</center>";
      }
      
      gaugeRotation.angle = gAngle;
      
    }
  }
  
  PlasmaCore.DataSource {
    id: gaugeData
    onNewData:{
      updateGauge(data)
    }
  }

  Timer {
      id: gaugeTest
      interval: 2000; running: false; repeat: false;
      onTriggered: { 
	if ( typeof gaugeData.connectedSources[0] == 'undefined' ) {
	  gaugeRotation.angle = iniSettings.angleLimits.min;
	}
	gaugeData.interval = gInterval * 1000;
      }
  }
  
  Image {
      id: gaugeBackground
      fillMode: Image.PreserveAspectFit
      smooth: true
      anchors.fill: parent
      height: gaugeBackground.height;
      width: gaugeBackground.width;
      sourceSize.height: gaugeBackground.height
      source: "../themes/" + gTheme + "/images/" + iniSettings.gaugeImage;
  }
  
  Rectangle {
    id: iconContainer
    clip: true
    width: parseInt(iniSettings.iconSize)
    height: parseInt(iniSettings.iconSize)
    x: (iniSettings.iconPosition.x / iniSettings.gaugeSize.x) * gaugeMain.width
    y: (iniSettings.iconPosition.y / iniSettings.gaugeSize.y) * gaugeMain.height
    color: "transparent"
  
    Image {
	id: gaugeIcon
	x: -(gIcon * iniSettings.iconSize)
	y: -(gIconColor * iniSettings.iconSize)
	sourceSize.height: gaugeIcon.height
	smooth: true
    }
  }
  
  Rectangle {
    x: gaugeBackground.width * (iniSettings.labelPosition.x / iniSettings.gaugeSize.x)
    y: gaugeBackground.height * (iniSettings.labelPosition.y / iniSettings.gaugeSize.y)
    color: "transparent"
    smooth: true
    
    Text {
      smooth: true
      id: gaugeLabel
      anchors.horizontalCenter: parent.horizontalCenter
      text: gLabel
      font: gFont
      color: gFontColor
    }
  }
  
  Image {
      id: gaugeNeedle
      height: Math.round(gaugeBackground.paintedHeight * (iniSettings.needleSize.y / iniSettings.gaugeSize.y));
      width: Math.round(gaugeBackground.paintedWidth * (iniSettings.needleSize.x / iniSettings.gaugeSize.x));
      y: (gaugeBackground.height * (iniSettings.gaugeCenter.y / iniSettings.gaugeSize.y)) - (gaugeNeedle.height * (iniSettings.needleCenter.y / iniSettings.needleSize.y))
      x: (gaugeBackground.width * (iniSettings.gaugeCenter.x / iniSettings.gaugeSize.x)) - (gaugeNeedle.width * (iniSettings.needleCenter.x / iniSettings.needleSize.x))
      sourceSize.height: gaugeNeedle.height
      source: "../themes/" + gTheme + "/images/" + iniSettings.needleImage;
      smooth: true
      fillMode: Image.PreserveAspectFit
      transform: Rotation {
	  id: gaugeRotation;
	  angle: iniSettings.angleLimits.min;
	  origin.x: gaugeNeedle.width * (iniSettings.needleCenter.x / iniSettings.needleSize.x); origin.y: gaugeNeedle.height * (iniSettings.needleCenter.y / iniSettings.needleSize.y);
	  Behavior on angle {
	    SpringAnimation { spring: 1; damping: 0.2; epsilon: 0.25 }
	  }
      }
  }
  
  Image {
      id: gaugeGlass
      fillMode: Image.PreserveAspectFit
      smooth: true
      anchors.fill: parent
      height: gaugeBackground.paintedHeight;
      width: gaugeBackground.paintedWidth;
      sourceSize.height: gaugeGlass.height
  }
} 
