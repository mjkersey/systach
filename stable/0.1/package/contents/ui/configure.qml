/*
 *   Copyright 2013 Michael Kersey <michael.kersey@gmail.com>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU Library General Public License as
 *   published by the Free Software Foundation; either version 2, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details
 *
 *   You should have received a copy of the GNU Library General Public
 *   License along with this program; if not, write to the
 *   Free Software Foundation, Inc.,
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

import QtQuick 1.1
import org.kde.plasma.core 0.1 as PlasmaCore
import org.kde.plasma.components 0.1 as PlasmaComponents
import org.kde.plasma.graphicswidgets 0.1 as PlasmaWidgets
import org.kde.plasma.extras 0.1 as PlasmaExtras
import "../code/systach-main.js" as STM

Rectangle {
  
  id: configForm
  width: 200
  height: 300
  anchors.top: parent.top
  anchors.left: parent.left
  anchors.topMargin: 10
  anchors.leftMargin: 10
  color: "transparent"
  
  Component.onCompleted: {
    STM.loadGaugeTypes(gaugeType);
  }
  
  PlasmaCore.DataSource {
    id: themeList
    engine: "filebrowser"
    connectedSources: [STM.packagePath + "/themes"]
    onNewData: {
      STM.loadThemes(data, gaugeTheme);
    }
  }

  PlasmaCore.DataSource {
    id: systemMonitor
    engine: "systemmonitor"
  }
  
  Grid {
    columns: 2
    spacing: 10
    anchors.fill: parent
    
    Text { text: "Gauge Configuration"; font.pixelSize: 16 }
    Rectangle { color: "transparent"; width: 200; height: 50 }
  
    Text { text: "Gauge Label" }
    PlasmaComponents.TextField { width: 200; id: gaugeLabel; text: "" }
    
    Text { text: "Gauge Theme" }
    PlasmaWidgets.ComboBox { width: 200; id: gaugeTheme; }

    Text { text: "Gauge Type" }
    PlasmaWidgets.ComboBox { width: 200; id: gaugeType; }
    
    Text { text: "Gauge Datasource" }
    PlasmaWidgets.ComboBox { width: 200; id: gaugeDatasource; }
    
    Text { text: "Update Interval (seconds)" }
    PlasmaWidgets.SpinBox { width: 50; id: gaugeInterval; }
  
  }
  
  Timer {
    id: sourceList
    interval: 1000; running: true; repeat: false;
    onTriggered:{ 
      STM.loadThemes(themeList.data, gaugeTheme); // On a timer, is blank if ran at runtime
    }
  }
}