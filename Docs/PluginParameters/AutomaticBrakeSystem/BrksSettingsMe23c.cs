namespace AtsPlugin.BrakeSystem
{
    public class BrksSettingsMe23c : AtsBehaviourSettingsBase
    {
        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public double ReleaseMvOpeningRatio { get; } = 0.25;

        [AtsBehaviourSettingsAttributes.UseDefaultOnLost]
        public bool HasReleaseMv { get; } = true;
    }
}
