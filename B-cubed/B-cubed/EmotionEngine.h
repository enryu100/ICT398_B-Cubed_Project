#pragma once
/********************************************//**
* \class EmotionEngine
* \brief the Emotion Engine used by the AI
* \details class used to manage the emotions of the NPCs
* \author Brandon Jin Yang Lim
* \version 1.0
* \date 2019
************************************************/
class EmotionEngine {
private:
	/**
* \addtogroup eAxes
	* \brief the Emotional Axes
	* \details the axes of emotion modeled as depicted in Plutchik's Wheel of Emotions
	* @{
	*/
	//variable declarations
	  /**
	  * \var joySad
	  * \brief Joy-Sadness axis
	  */
	float joySad;
	/**
	* \var trustDisgust
	* \brief Trust-Disgust axis
	*/
	float trustDisgust;
	/**
	* \var fearRage
	* \brief Fear-Anger axis
	*/
	float fearRage;
	/**
	* \var surpriseAnticipation
	* \brief Surprise-Anticipation axis
	*/
	float surpriseAnticipation;
	/** @} */

	/**
* \addtogroup eModifiers
	* \brief an NPCs emotion modified
	* \details a set of modifiers which affect the extent at which emotions affect an NPC. used to simulate unique personalities. each emotion (not each axis) has a separate modifier
	* @{
	*/
	/**
	* \var initialJS
	* \brief baseline Joy-Sadness value
	*/
	float initialJS;
	/**
	* \var initialTD
	* \brief baseline Trust-Disgust value
	*/
	float initialTD;
	/**
	* \var initialFR
	* \brief baseline Fear-Anger value
	*/
	float initialFR;
	/**
	* \var initialSA
	* \brief baseline Surprise-Anticipation value
	*/
	float initialSA;
	/** @} */

	/**
* \addtogroup eModifiers
	* \brief an NPCs emotion modified
	* \details a set of modifiers which affect the extent at which emotions affect an NPC. used to simulate unique personalities. each emotion (not each axis) has a separate modifier
	* @{
	*/
	/**
	* \var joyMod
	* \brief Joy modifier
	*/
	float joyMod;
	/**
	* \var sadMod
	* \brief Sadness modifier
	*/
	float sadMod;
	/**
	* \var trustMod
	* \brief Trust modifier
	*/
	float trustMod;
	/**
	* \var disgustMod
	* \brief Disgust modifier
	*/
	float disgustMod;
	/**
	* \var fearMod
	* \brief Fear modifier
	*/
	float fearMod;
	/**
	* \var rageMod
	* \brief Anger modifier
	*/
	float rageMod;
	/**
	* \var surpriseMod
	* \brief Surprise modifier
	*/
	float surpriseMod;
	/**
	* \var anticipationMod
	* \brief Anticipation modifier
	*/
	float anticipationMod;
	/** @} */

	/**
	* \var angleOfView
	* \brief NPC's Angle of View
	* \details the Angle of View of the NPC, which will be affected by their mood
	*/
	float angleOfView;
	/**
	* \var depthOfView
	* \brief NPC's Depth of View
	* \details the Depth of View of the NPC, which will be affected by their mood
	*/
	float depthOfView;

	/**
	* \var emotionThreshold
	* \brief Emotion threshold before reaction
	* \details the level which an emotion mus surpass before a reaction occurs
	*/
	float emotionThreshold;

	/**
	* \var decayRate
	* \brief Emotion decay rate
	* \details the rate at which he NPC returns to their baseline emotional state
	*/
	float decayRate;

	/********************************************//**
	 * \fn normalizeEmotions
	 * \brief ensures emotion values don't exceed maximums
	 * \details Manipulates the emotion variables to ensure only 1 value reaches the maximum at a time, and no value can be excessively high
	 * \author Brandon Jin Yang Lim
	 ***********************************************/
	void normalizeEmotions();

public:
	/**
  * \addtogroup constructors
	  * \brief constructors
	  * \details constructors for the EmotionEngine
	  * @{
	  */

	  /********************************************//**
	  * \fn EmotionEngine()
	  * \brief default constructor
	  * \details default constructor for the emotion engine. sets all values to 0 during initialisation
	  ************************************************/
	EmotionEngine();
	/********************************************//**
	* \fn EmotionEngine(float js, float td, float fr, float sa, float jm, float sadm, float tm, float dm, float fm, float rm, float surpm, float am)
	* \brief overloaded constructor
	* \details overloaded constructor which sets all variables
	* \param js the initial joySadness level
	* \param td the initial trustDisgust level
	* \param fr the initial fearRage level
	* \param sa the initial surpriseAnticipation level
	* \param jm the joy gain modifier
	* \param sadm the sadness gain modifier
	* \param tm the trust gain modifier
	* \param dm the disgust gain modifier
	* \param fm the fear gain modifier
	* \param rm the anger gain modifier
	* \param surpm the surprise gain modifier
	* \param am the anticipation gain modifier
	* \param aov the NPC's default angle of view
	* \param dov the NPC's default depth of view
	* \param dr the rate at which the NPC returns to emotional baseline
	* \param et the threshold at which the NPC acts according to an emotion
	************************************************/
	EmotionEngine(float js, float td, float fr, float sa, float jm, float sadm, float tm, float dm, float fm, float rm, float surpm, float am, float aov, float dov, float dr, float et);
	/** @} */

	  //increase emotion functions
	  /********************************************//**
	  * \defgroup emotionIncrease
	  * \brief Emotion value increase functions
	  * @{
	  ***********************************************/
	  /********************************************//**
	  * \fn addJoy
	  * \brief Adds to the value of Joy
	  * \details Parameter passed is added to the value of joy (reducing sadness), then emotions are normalized. Returns a 1 if the emotion value passes a given threshold
	  * \param[in] joyVal Amount to increase joy by.
	  * \author Brandon Jin Yang Lim
	  * \return flag showing whether emotion has passed threshold
	  ***********************************************/
	int addJoy(float joyVal);

	/********************************************//**
	* \fn addJoy
	* \brief Adds to the value of Sadness
	* \details Parameter passed is added to the value of sadness (reducing joy), then emotions are normalized. Returns a 1 if the emotion value passes a given threshold
	* \param[in] sadVal Amount to increase sadness by.
	* \author Brandon Jin Yang Lim
	* \return flag showing whether emotion has passed threshold
	***********************************************/
	int addSad(float sadVal);

	/********************************************//**
	* \fn addTrust
	* \brief Adds to the value of Trust
	* \details Parameter passed is added to the value of trust (reducing disgust), then emotions are normalized. Returns a 1 if the emotion value passes a given threshold
	* \param[in] trustVal Amount to increase trust by.
	* \author Brandon Jin Yang Lim
	* \return flag showing whether emotion has passed threshold
	***********************************************/
	int addTrust(float trustVal);

	/********************************************//**
	* \fn addDisgust
	* \brief Adds to the value of Disgust
	* \details Parameter passed is added to the value of disgust (reducing trust), then emotions are normalized. Returns a 1 if the emotion value passes a given threshold
	* \param[in] disgVal Amount to increase disgust by.
	* \author Brandon Jin Yang Lim
	* \return flag showing whether emotion has passed threshold
	***********************************************/
	int addDisgust(float disgVal);

	/********************************************//**
	* \fn addFear
	* \brief Adds to the value of Fear
	* \details Parameter passed is added to the value of fear (reducing anger), then emotions are normalized. Returns a 1 if the emotion value passes a given threshold
	* \param[in] fearVal Amount to increase fear by.
	* \author Brandon Jin Yang Lim
	* \return flag showing whether emotion has passed threshold
	***********************************************/
	int addFear(float fearVal);

	/********************************************//**
	* \fn addAnger
	* \brief Adds to the value of Anger
	* \details Parameter passed is added to the value of anger (reducing fear), then emotions are normalized. Returns a 1 if the emotion value passes a given threshold
	* \author Brandon Jin Yang Lim
	* \return flag showing whether emotion has passed threshold
	***********************************************/
	int addAnger(float angVal);

	/********************************************//**
	* \fn addSurprise
	* \brief Adds to the value of Surprise
	* \details Parameter passed is added to the value of surprise (reducing anticipation), then emotions are normalized. Returns a 1 if the emotion value passes a given threshold
	* \param[in] surpVal Amount to increase surprise by.
	* \author Brandon Jin Yang Lim
	* \return flag showing whether emotion has passed threshold
	***********************************************/
	int addSurprise(float surpVal);

	/********************************************//**
	* \fn addAnticipation
	* \brief Adds to the value of Anticipation
	* \details Parameter passed is added to the value of anticipation (reducing surprise), then emotions are normalized. Returns a 1 if the emotion value passes a given threshold
	* \param[in] anticVal Amount to increase anticipation by.
	* \author Brandon Jin Yang Lim
	* \return flag showing whether emotion has passed threshold
	***********************************************/
	int addAnticipation(float anticVal);
	/**
	* @} //end of EmotionIncrease group
	*/

	//getter functions
	/********************************************//**
	* \defgroup getters
	* \brief Get Value functions
	* @{
	***********************************************/
	/********************************************//**
	* \fn getJoySad
	* \brief gets the value on the Joy-Sadness axis
	* \author Brandon Jin Yang Lim
	* \return value of joySad
	***********************************************/
	float getJoySad() { return joySad; }

	/********************************************//**
	* \fn getTrustDisgust
	* \brief gets the value on the Trust-Disgust axis
	* \author Brandon Jin Yang Lim
	* \return value of trustDisgust
	***********************************************/
	float getTrustDisgust() { return trustDisgust; }

	/********************************************//**
	* \fn getFearAnger
	* \brief gets the value on the Fear-Anger axis
	* \author Brandon Jin Yang Lim
	* \return value of fearRage
	***********************************************/
	float getFearAnger() { return fearRage; }

	/********************************************//**
	* \fn getSurpriseAnticipation
	* \brief gets the value on the Surprise-Anticipation axis
	* \author Brandon Jin Yang Lim
	* \return value of surpriseAnticipation
	***********************************************/
	float getSurpriseAnticipation() { return surpriseAnticipation; }

	/********************************************//**
	* \fn getEmotionThreshold
	* \brief gets the emotionThreshold value
	* \author Brandon Jin Yang Lim
	* \return value of emotion_threshold
	***********************************************/
	float getEmotionThreshold() { return emotionThreshold; }

	/********************************************//**
	* \fn getDepthOfView
	* \brief gets the depth of view of the NPC
	* \details depth of view is calculated based on emotional state
	* \author Brandon Jin Yang Lim
	* \return depth of view, in units
	***********************************************/
	float getDepthOfView() { return depthOfView; }

	/********************************************//**
	* \fn getAngleOfView
	* \brief gets the angle of view of the NPC
	* \author Brandon Jin Yang Lim
	* \return angle of view, in degrees
	***********************************************/
	float getAngleOfView() { return angleOfView; }
	/********************************************//**
	* @}
	***********************************************/

	//calculate view angle/depth
	/********************************************//**
	* \fn calcViewData
	* \brief calculates the depth and angle of view
	* \details calculates depth and angle of view based on emotional state.
	* \todo use actual calculations instead of two sets of arbitrary values.
	* \author Brandon Jin Yang Lim
	***********************************************/
	void calcViewData();

	//emotion decay function
	/********************************************//**
	* \fn decayEmotions
	* \brief reduces emotions towards their axes' centres
	* \details divides emotion values by a set amount whenever called.
	* \pre should be called within a timer function
	* \warning beta version. does not work perfectly.
	* \author Brandon Jin Yang Lim
	***********************************************/
	void decayEmotions();

	/********************************************//**
	* \defgroup setters Setter functions
	* @{
	***********************************************/

	//setter funcs for modifiable values
	/********************************************//**
	* \fn setEmotionThreshold
	* \brief sets threshold at which response is triggered
	* \param[in] emotion_threshold Value to which the emotion threshold is to be set.
	* \author Brandon Jin Yang Lim
	***********************************************/
	void setEmotionThreshold(float emotion_threshold);

	//set emotion levels (for use with generic constructor)
	/********************************************//**
	* \fn setEmotionLevels
	* \brief sets the values for each emotion axis
	* \param[in] joy Intended value of joySad.
	* \param[in] trust Intended value of trustDisgust.
	* \param[in] fear Intended value of fearRage.
	* \param[in] surprise Intended value of surpriseAnticipation.
	* \author Brandon Jin Yang Lim
	***********************************************/
	void setEmotionLevels(float joy,
		float trust,
		float fear,
		float surprise);

	//set an Agent's modifiers to how quickly they gain points to an emotion
	/********************************************//**
	* \fn setJoyModifier
	* \brief sets the modifier for joy input
	* \param[in] joy_m Intended joy modifier.
	* \author Brandon Jin Yang Lim
	***********************************************/
	void setJoyModifier(float joy_m);

	/********************************************//**
	* \fn setTrustModifier
	* \brief sets the modifier for trust input
	* \param[in] trust_m Intended trust modifier.
	* \author Brandon Jin Yang Lim
	***********************************************/
	void setTrustModifier(float trust_m);

	/********************************************//**
	* \fn setFearModifier
	* \brief sets the modifier for fear input
	* \param[in] fear_m Intended fear modifier.
	* \author Brandon Jin Yang Lim
	***********************************************/
	void setFearModifier(float fear_m);

	/********************************************//**
	* \fn setSurpriseModifier
	* \brief sets the modifier for surprise input
	* \param[in] surprise_m Intended surprise modifier.
	* \author Brandon Jin Yang Lim
	***********************************************/
	void setSurpriseModifier(float surprise_m);

	/********************************************//**
	* \fn setSadnessModifier
	* \brief sets the modifier for sadness input
	* \param[in] sadness_m Intended sadness modifier.
	* \note Is separate to joy modifier to be more realistic
	* \author Brandon Jin Yang Lim
	***********************************************/
	void setSadnessModifier(float sadness_m);

	/********************************************//**
	* \fn setDisgustModifier
	* \brief sets the modifier for disgust input
	* \param[in] disgust_m Intended disgust modifier.
	* \note Is separate to trust modifier to be more realistic
	* \author Brandon Jin Yang Lim
	***********************************************/
	void setDisgustModifier(float disgust_m);

	/********************************************//**
	* \fn setAngerModifier
	* \brief sets the modifier for anger input
	* \param[in] anger_m Intended anger modifier.
	* \note Is separate to fear modifier to be more realistic
	* \author Brandon Jin Yang Lim
	***********************************************/
	void setAngerModifier(float anger_m);

	/********************************************//**
	* \fn setAnticipationModifier
	* \brief sets the modifier for anticipation input
	* \param[in] anticipation_m Intended anticipation modifier.
	* \note Is separate to surprise modifier to be more realistic
	* \author Brandon Jin Yang Lim
	***********************************************/
	void setAnticipationModifier(float anticipation_m);

	/********************************************//**
	* @}
	***********************************************/

	/********************************************//**
	* \fn testEmotionForResponse
	* \brief tests emotion to see if response should be given
	* \param[in] emotion emotion to be tested
	* \author Brandon Jin Yang Lim
	***********************************************/
	int testEmotionForResponse(float emotion);
};