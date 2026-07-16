   install(
        TARGETS ${PROJECT_NAME}
        EXPORT DOENGINETargets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    )

    install(
        DIRECTORY includes/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
    )

    install(
        DIRECTORY assets/
        DESTINATION ${CMAKE_INSTALL_DATADIR}/${PROJECT_NAME}
    )

    install(
        EXPORT DOENGINETargets
        FILE DOENGINETargets.cmake
        NAMESPACE DOENGINE::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/DOENGINE
    )

    # Minimal package config so downstream projects can do
    # find_package(DOENGINE CONFIG REQUIRED) and link DOENGINE::DOENGINE.
    set(DOENGINE_CONFIG_IN ${CMAKE_CURRENT_BINARY_DIR}/DOENGINEConfig.cmake.in)
    file(WRITE ${DOENGINE_CONFIG_IN}
"@PACKAGE_INIT@\n\ninclude(CMakeFindDependencyMacro)\nfind_dependency(OpenGL)\nfind_dependency(SDL2)\nfind_dependency(SDL2_ttf)\nfind_dependency(SDL2_image)\nfind_dependency(SDL2_mixer)\nfind_dependency(glm)\n\ninclude(\"\${CMAKE_CURRENT_LIST_DIR}/DOENGINETargets.cmake\")\n"
    )

    configure_package_config_file(
        ${DOENGINE_CONFIG_IN}
        ${CMAKE_CURRENT_BINARY_DIR}/DOENGINEConfig.cmake
        INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/DOENGINE
    )

    write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/DOENGINEConfigVersion.cmake
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion
    )

    install(
        FILES
            ${CMAKE_CURRENT_BINARY_DIR}/DOENGINEConfig.cmake
            ${CMAKE_CURRENT_BINARY_DIR}/DOENGINEConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/DOENGINE
    )

