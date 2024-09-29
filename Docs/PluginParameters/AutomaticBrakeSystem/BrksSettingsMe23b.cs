namespace AtsPlugin.BrakeSystem
{
    public class BrksSettingsMe23b : AtsBehaviourSettingsBase
    {
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double ReleaseMvOpeningRatio { get; } = 0.25;
    }
}
