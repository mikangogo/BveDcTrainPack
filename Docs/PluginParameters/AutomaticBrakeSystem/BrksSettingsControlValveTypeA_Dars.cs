namespace AtsPlugin.BrakeSystem
{
    public class BrksSettingsControlValveTypeA_Dars : AtsBehaviourSettingsBase
    {
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double BrakeMvOpeningRatio { get; } = 0.01;
    }
}
