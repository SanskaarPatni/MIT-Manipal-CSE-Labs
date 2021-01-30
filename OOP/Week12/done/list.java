import javafx.application.*;
import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.geometry.*;
import javafx.beans.value.*;
import javafx.collections.*;
public class list  extends Application {
Label response;
public static void main(String[] args) {
// Start the JavaFX application by calling launch().
launch(args);
}
// Override the start() method.
public void start(Stage myStage) {
// Give the stage a title.
myStage.setTitle("ListView Demo");
// Use a FlowPane for the root node. In this case,
// vertical and horizontal gaps of 10.
FlowPane rootNode = new FlowPane(10, 10);
// Center the controls in the scene.
rootNode.setAlignment(Pos.CENTER);
// Create a scene.
Scene myScene = new Scene(rootNode, 500, 120);
// Set the scene on the stage.
myStage.setScene(myScene);
// Create a label.
response = new Label("Select Transport Type");
// Create an ObservableList of entries for the list view.
ObservableList<String> transportTypes =
FXCollections.observableArrayList( "Train", "Car", "Airplane" );
// Create the list view.
ListView<String> lvTransport = new ListView<String>(transportTypes);
// Set the preferred height and width.
lvTransport.setPrefSize(80, 80);
// Get the list view selection model.
MultipleSelectionModel<String> lvSelModel =
lvTransport.getSelectionModel();
// Use a change listener to respond to a change of selection within
// a list view.
lvSelModel.selectedItemProperty().addListener(
new ChangeListener<String>() {
public void changed(ObservableValue<? extends String> changed,
String oldVal, String newVal) {
// Display the selection.
response.setText("Transport selected is " + newVal);
}
});// Add the label and list view to the scene graph.
rootNode.getChildren().addAll(lvTransport, response);
// Show the stage and its scene.
myStage.show();
}
}
