export PATH_TO_FX="/home/sanskaar/Desktop/openjfx-11.0.2_linux-x64_bin-sdk/javafx-sdk-11.0.2/lib/"
javac --module-path $PATH_TO_FX --add-modules javafx.controls $1.java && java --module-path $PATH_TO_FX --add-modules javafx.controls $1
