import QtQuick 1.1
import org.kde.plasma.core 0.1 as PlasmaCore
import org.kde.plasma.components 0.1 as PlasmaComponents
import "../code/systach-main.js" as JS

Item {
  
    id: mainContainer
    property real xRot
    property real yRot
    property real xPos
    property real yPos
    
    anchors.fill: parent
    
    property string qmlFile
    property int anTriggered
    
    signal configChanged()
    signal setAuto(double rLow, double rHigh)
    signal gaugeValue(variant gValue)
    signal getPackagePath()
    signal reloadConfig()
    
    MouseArea {
      id: clickArea
      anchors.fill: parent
      onPressed: {
	xPos = mouseX;
	yPos = mouseY;
      }
      onPositionChanged: {
	xDiff = mouseX - xPos;
	yDiff = mouseY - yPos;
	xRot += yDiff;
	yRot += xDiff;
	if (xRot > 60) { xRot = 60; }
	if (yRot > 60) { yRot = 60; }
	if (xRot < -60) { xRot = -60; }
	if (yRot < -60) { yRot = -60; }
	if (Math.abs(xRot) <= 10) { xRot = 0; }
	if (Math.abs(yRot) <= 10) { yRot = 0; }
// 	  rectRotate.scale= 1 + (Math.abs(xRot) + Math.abs(yRot) + 1) / 241;
	xPos = mouseX;
	yPos = mouseY;
      }
    }
    
    Component.onCompleted: { 
      JS.initialize();
      JS.updateLoader();
    }
    
    onReloadConfig: {
      JS.updateLoader();
    }

    Rectangle {
      id: rectRotate
      anchors.fill: parent
      color: "transparent"
      anchors {
	left: parent.left
	top: parent.top
      }
      
      smooth: true
      transform: [ 
	Rotation { 
	  id: xRotate
	  origin.x: rectRotate.width / 2;
	  origin.y: rectRotate.height / 2;
	  axis { x: 1; y: 0; z: 0 }
	  angle: xRot;
	  },
	Rotation { 
	  id: yRotate
	  origin.x: rectRotate.width / 2;
	  origin.y: rectRotate.height / 2;
	  axis { x: 0; y: 1; z: 0 }
	  angle: yRot;
	}
      ]

      Loader { 
	id: mainLoader 
	anchors.fill: parent
      }
      
      Rectangle {
	//color: "#000"
	opacity: 0.8
	smooth: true
	anchors {
	  horizontalCenter: parent.horizontalCenter
	  verticalCenter: parent.verticalCenter
	}
	  Text {
	      id: qMessages
	      anchors {
		  horizontalCenter: parent.horizontalCenter
		  verticalCenter: parent.verticalCenter
	      }
	      text: "<center>No gauge configured.<br> Select one in Settings.</center>"
	      font.family: "Helvetica"
	      font.pixelSize: 14
	      color: "#EEE"
	  }
	  //width: childrenRect.width * 1.1
	  //height: childrenRect.height * 1.1
      }
    }
}