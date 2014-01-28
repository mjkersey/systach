project(systach)
find_package(KDE4 REQUIRED)

include (KDE4Defaults)
include(MacroLibrary)

include_directories (${KDE4_INCLUDES})

set(systach_SRCS
    systach.cpp
)

kde4_add_ui_files(systach_SRCS
    generalSettings.ui
    datasourceSettings.ui
    advancedSettings.ui
)

kde4_add_plugin(plasma_applet_systach ${systach_SRCS})
kde4_add_app_icon(plasma_applet_systach_SRCS "hi256-apps-systach.png")


target_link_libraries(plasma_applet_systach
    ${KDE4_KDEUI_LIBS}
    ${KDE4_PLASMA_LIBS}
    ${QT_QTDECLARATIVE_LIBRARY}
)


install(TARGETS plasma_applet_systach DESTINATION ${PLUGIN_INSTALL_DIR})

install(DIRECTORY ../package/ DESTINATION ${DATA_INSTALL_DIR}/plasma/packages/systach PATTERN .svn EXCLUDE)
install(FILES plasma-applet-systach.desktop DESTINATION ${SERVICES_INSTALL_DIR}) 
kde4_install_icons( ${ICON_INSTALL_DIR} )
kde4_update_iconcache()
