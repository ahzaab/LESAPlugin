import gfx.controls.Button;
import gfx.io.GameDelegate;
import skyui.util.Debug;
import Shared.GlobalFunc;
import gfx.events.EventDispatcher;
import gfx.events.EventTypes;
import gfx.managers.FocusHandler;
import gfx.ui.InputDetails;
import gfx.ui.NavigationCode;

dynamic class LevelUpMenu extends MovieClip
{
	var LevelUpMenuHeader: MovieClip;
	var titleText: TextField;
	var choicesRemaining_mc: MovieClip;
	var choicesRemainingText: TextField;

	var StrengthButton: Button;
	var EnduranceButton: Button;
	var IntelligenceButton: Button;
	var WillpowerButton: Button;
	var AgilityButton: Button;
	var SpeedButton: Button;
	var PersonalityButton: Button;
	var LuckButton: Button;
	var ConfirmButton: Button;

	var StrengthVal: TextField;
	var EnduranceVal: TextField;
	var IntelligenceVal: TextField;
	var WillpowerVal: TextField;
	var AgilityVal: TextField;
	var SpeedVal: TextField;
	var PersonalityVal: TextField;
	var LuckVal: TextField;
	var ConfirmVal: TextField;
	
	var aButtons: Array;
	var aOnPressFunctions: Array;
	var aTargetAVs: Array;
	var aTextFields: Array;
	var aOpeningValues: Array;
	var aCurrentValues: Array;

	var numChoicesLeft: Number;

	var levelUpColour: Number = 0x2ad400; // Green

	var NavigationMap:Array;
	var MAX_COLUMN:Number = 2;
	var MAX_ROWS:Number = 4;
	var currentColIdx:Number = 0;
	var currentRowIdx:Number = 0;

	function LevelUpMenu()
	{
		super();

		this._visible = false;

		LevelUpMenuHeader = LevelUpMenuHeader;
		titleText = LevelUpMenuHeader.titleText;
		choicesRemaining_mc = choicesRemaining_mc;
		choicesRemainingText = choicesRemaining_mc.choicesRemainingText;

		StrengthButton = StrengthButton;
		EnduranceButton = EnduranceButton;
		IntelligenceButton = IntelligenceButton;
		WillpowerButton = WillpowerButton;
		AgilityButton = AgilityButton;
		SpeedButton = SpeedButton;
		PersonalityButton = PersonalityButton;
		LuckButton = LuckButton;
		ConfirmButton = ConfirmButton;

		StrengthVal = StrengthVal;
		EnduranceVal = EnduranceVal;
		IntelligenceVal = IntelligenceVal;
		WillpowerVal = WillpowerVal;
		AgilityVal = AgilityVal;
		SpeedVal = SpeedVal;
		PersonalityVal = PersonalityVal;
		LuckVal = LuckVal;
		ConfirmVal = ConfirmVal;

		aButtons = new Array(StrengthButton, EnduranceButton, IntelligenceButton, WillpowerButton, AgilityButton, SpeedButton, PersonalityButton, LuckButton);
		aOnPressFunctions = new Array("onStrengthPressed", "onEndurancePressed", "onIntelligencePressed", "onWillpowerPressed", "onAgilityPressed", "onSpeedPressed", "onPersonalityPressed", "onLuckPressed")
		aTextFields = new Array(StrengthVal, EnduranceVal, IntelligenceVal, WillpowerVal, AgilityVal, SpeedVal, PersonalityVal, LuckVal);
		aTargetAVs = new Array("ShieldPerks", "LastFlattered", "LastBribedIntimidated", "WardDeflection", "FavorPointsBonus", "DetectLifeRange", "FavorsPerDay", "Nighteye");
		aOpeningValues = new Array();
		aCurrentValues = new Array();
		
		NavigationMap = [[StrengthButton, IntelligenceButton, SpeedButton, PersonalityButton], 
						 [EnduranceButton, WillpowerButton, AgilityButton, LuckButton]];
		
				
	}

	public function onLoad():Void 
	{
		skyui.util.Debug.log("onLoad");
		// Make sure this gets initial focus
		FocusHandler.instance.setFocus(this,0);
		currentColIdx = 0;
		currentRowIdx = 0;
		Selection.setFocus(NavigationMap[0][0]);
	}

	public function handleInput(details: InputDetails, pathToFocus: Array): Boolean
	{
		skyui.util.Debug.log("handleInput: details.value:" + details.value + " details.navEquivalent: " + details.navEquivalent);
		var inputHandled:Boolean = false;
		var focuedObject:Object;

		var nextClip = pathToFocus.shift();
		skyui.util.Debug.log("nextClip: " + nextClip);
		//if (nextClip && nextClip.handleInput(details, pathToFocus))
			//return true;

		if (GlobalFunc.IsKeyPressed(details))
		{
			skyui.util.Debug.log("handleInput Press");
			if (details.navEquivalent == NavigationCode.RIGHT)
			{
				if (currentColIdx < MAX_COLUMN-1)
				{
					currentColIdx++;
				}
				inputHandled = true;
			}
			else if (details.navEquivalent == NavigationCode.LEFT)
			{
				if (currentColIdx > 0)
				{
					currentColIdx--;
				}
				inputHandled = true;
			}
			else if (details.navEquivalent == NavigationCode.UP)
			{
				if (currentRowIdx > 0)
				{
					currentRowIdx--;
				}
				inputHandled = true;
			}
			else if (details.navEquivalent == NavigationCode.DOWN)
			{
				if (currentRowIdx < MAX_ROWS)
				{
					currentRowIdx++;
				}
				inputHandled = true;
			}					
			//focuedObject.selected = true;
			//focuedObject.displayFocus = true;
			if (inputHandled){
				skyui.util.Debug.log("Col: " + currentColIdx + " Row: " + currentRowIdx);
				if (currentRowIdx < MAX_ROWS)
				{
					focuedObject = NavigationMap[currentColIdx][currentRowIdx];
				}
				else
				{
					focuedObject = ConfirmButton;
				}				
				Selection.setFocus(focuedObject);
			}			
		}

		return inputHandled;

	}


	function InitExtensions(): Void
	{
		var targetButton: Button;
		skyui.util.Debug.log("InitExtensions");
		for (var i: Number = 0; i < aButtons.length; i++) {
			targetButton = aButtons[i];
			targetButton.addEventListener("press", this, aOnPressFunctions[i])
			targetButton.addEventListener("focusOut", this, "playFocusSound");
			targetButton.addEventListener("rollOver", this, "playFocusSound");
		}
	}
		
	public function setInitialValues(/* values */): Void 		// Called from papyrus when OnMenuOpen received for LevelUpMenu - sets the opening attribute values and header text
    {		
        var targetText: TextField;
        var textFormat: TextFormat;
		skyui.util.Debug.log("setInitialValues");
        numChoicesLeft = 3;

        for (var i: Number = 0; i < 8; i++) {
        	var val: Number = arguments[i];
        	aOpeningValues[i] = val;
			aCurrentValues[i] = val;
        	targetText = aTextFields[i];
			textFormat = targetText.getTextFormat();
			targetText.text = val.toString();
			targetText.setTextFormat(textFormat);
		}

		textFormat = titleText.getTextFormat();
		titleText.text = arguments[8];
		titleText.setTextFormat(textFormat);

		updateChoicesRemaining();

		ConfirmButton._visible = false;  						// Confirm button is initially hidden until all three selections have been made
		this._visible = true;
    }

	function handleButtonPress(i: Number): Void
	{
		skyui.util.Debug.log("handleButtonPress: " + i);
		var valueChanged: Boolean = true;

		var targetText: TextField = aTextFields[i];
        var textFormat: TextFormat = targetText.getTextFormat();
		
		if(aCurrentValues[i] == aOpeningValues[i] && numChoicesLeft > 0){
			var val: Number = aCurrentValues[i];
			textFormat.color = levelUpColour;
			numChoicesLeft -= 1;
			aCurrentValues[i] = (val + 3);
		}else if(aCurrentValues[i] > aOpeningValues[i]){
			textFormat.color = 0xFFFFFF; // White
			numChoicesLeft += 1;
			aCurrentValues[i] = aOpeningValues[i];
		}else{
			valueChanged = false;
		}

		if(valueChanged){
			targetText.text = aCurrentValues[i].toString();
			targetText.setTextFormat(textFormat);
			GameDelegate.call("PlaySound", ["UIMenuOK"]);
			if(numChoicesLeft > 0)
				updateChoicesRemaining();
		}

		if(numChoicesLeft > 0){
			ConfirmButton._visible = false;
			choicesRemainingText._visible = true;
		}else{
			choicesRemainingText._visible = false;
			ConfirmButton._visible = true;
			ConfirmButton.addEventListener("press", this, "onConfirmPressed")
			ConfirmButton.addEventListener("focusOut", this, "playFocusSound");
			ConfirmButton.addEventListener("rollOver", this, "playFocusSound");
		}
	}

	function updateChoicesRemaining(): Void
	{
		var textFormat:TextFormat = choicesRemainingText.getTextFormat();
		choicesRemainingText.text = "Choose " + numChoicesLeft + " attributes to improve";
		choicesRemainingText.setTextFormat(textFormat);
	}

	function onConfirmPressed(): Void
	{
		if(numChoicesLeft == 0){								// If the player has made all three choices and presses the Confirm button
			GameDelegate.call("PlaySound", ["UIMenuOK"]);
			if(_global.skse){
				for (var i: Number = 0; i < 8; i++) {
					if(aCurrentValues[i] > aOpeningValues[i])	// Find the three attributes that have been changed and send mod events back to papyrus to set the AVs to the new values
						skse.SendModEvent("levelUpMenuAttributesConfirmed", aTargetAVs[i], aCurrentValues[i]);
				}
				GameDelegate.call("CloseMenu",[]);
			}else if(_global.gfxPlayer){
  				trace("LevelUpMenu onConfirmPress - Something went wrong");
  				GameDelegate.call("CloseMenu",[]);
			}
		}
	}
	
	function playFocusSound(): Void
	{
		GameDelegate.call("PlaySound", ["UIMenuFocus"]);
	}

	function onStrengthPressed(): Void
	{
		handleButtonPress(0);
	}

	function onEndurancePressed(): Void
	{
		handleButtonPress(1);
	}

	function onIntelligencePressed(): Void
	{
		handleButtonPress(2);
	}

	function onWillpowerPressed(): Void
	{
		handleButtonPress(3);
	}

	function onAgilityPressed(): Void
	{
		handleButtonPress(4);
	}

	function onSpeedPressed(): Void
	{
		handleButtonPress(5);
	}

	function onPersonalityPressed(): Void
	{
		handleButtonPress(6);
	}

	function onLuckPressed(): Void
	{
		handleButtonPress(7);
	}
}
