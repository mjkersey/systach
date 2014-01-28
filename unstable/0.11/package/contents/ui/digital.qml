import QtQuick 1.1
import org.kde.plasma.core 0.1 as PlasmaCore
import "../plasmapackage:/code/systach-main.js" as STM

Item {
  
  id: odoMain
  //width: 175; height: 45
  anchors.top: parent.top
  anchors.left: parent.left
  anchors.fill: parent

  Component.onCompleted: { 
    //STM.initialize()
    plasmoid.setBackgroundHints(NoBackground);
    plasmoid.resize(175,25);
  }
  
  PlasmaCore.DataSource {
    id: cpuUsage
    engine: "systemmonitor"
    connectedSources: ["system/uptime"]
    interval: 5000

    onNewData:{
      function updateUptime(seconds) {
	if(!isNaN(seconds)){
	  var days = STM.padToLength(Math.floor(seconds / 86400),5);
	  var hours = STM.padToLength(Math.floor((seconds % 86400) / 3600),2);
	  var minutes = STM.padToLength(Math.floor(((seconds % 86400) % 3600) / 60),2);
	  odoText.text = days;
	  odoText.text += " " + hours;
	  odoText.text += " " + minutes;
	}	
      }
      updateUptime(data.value)
    }
  }
  
  Image {
      id: odoBackground
      fillMode: Image.PreserveAspectFit
      smooth: true
      anchors.fill: parent
      sourceSize.height: odoBackground.height
      //sourceSize.width: odoBackground.width
      source: "plasmapackage:/themes/light/images/odo-bg.svg"
  }
  
  FontLoader {
      id: segment7
      source: "plasmapackage:/resources/segment-7.ttf"
  }

  Text {
      id: odoText
      x: odoBackground.width * 0.229
      y: odoBackground.height * 0.2
      text: "88888 88 88"
      font.family: segment7.name
      font.pixelSize: odoBackground.height * 0.8
  }
  
  Text {
      y: odoBackground.height + odoBackground.height * 0.1
      anchors {
	horizontalCenter: parent.horizontalCenter
      }
      text: plasmoid.readConfig("gaugeLabel");
      font.family: "Helvetica"
      font.pixelSize: odoBackground.height * 0.4
      style: Text.Outline
      styleColor: "#222"
      color: "#EEE"
  }
} 
