function initialize() {
  
  

}

// Pad numbers to length, useful for "fixed digit" displays
function padToLength(number,length) {
  if (number <= 9999) { number = ("000000" + number).slice(0 - length); }
  return number;
}


// Clears the loader, and (re)loads a QML object
function loadSelected(displayType) {
  if(displayType != "") {
      qMessages.text = "";
//       if ( mainContainer.qmlFile != displayType + ".qml" ) {   // need property bindings to work for this
	mainContainer.qmlFile = iniSettings.displayType + ".qml";
	mainLoader.source = ""; //clear loader
	mainLoader.source = qmlFile;
//       }
  }
}

// Loads a QML object into the main loader
function updateLoader() {
  if (typeof iniSettings != 'undefined') {
    loadSelected(iniSettings.displayType);
  }  
}

// Loads the glass images, if defined
function loadGlass() {
  if (iniSettings.glassImage) {
    gaugeGlass.source = "../themes/" + gTheme + "/images/" + iniSettings.glassImage;
  }
}

function loadIcon() {
  if (gShowIcon == 'true') {
    gaugeIcon.source = "../themes/" + gTheme + "/resources/icons.svg";
  }
}

// Grabs INI settings, and configures the engine and datasource with some defaults, if defined
function configureEngine() {
    if ( gDatasource == '' ) {
      if ( !iniSettings.dataSource == '' ) {
	gaugeData.connectedSources = iniSettings.dataSource;
      } else {
	qMessages.text = "<center>No datasource<br> selected!</center>";
      }
    } else {
      gaugeData.connectedSources = gDatasource
      //gaugeData.connectedSources[0] = "network/interfaces/wlan1/receiver/data";
      //gaugeData.connectedSources[1] = "network/interfaces/wlan1/transmitter/data";
  }
  
  if ( gDataengine == '' ) {
    if ( !iniSettings.dataEngine == '' ) {
      gaugeData.engine = iniSettings.dataEngine[0]; // Returned as a QVariantList, so we tell it to use the 1st and only element
    } else {
      gaugeData.engine = "systemmonitor" // Give up, and assign the default engine
    }
  } else {
    gaugeData.engine = gDataengine
  }
}