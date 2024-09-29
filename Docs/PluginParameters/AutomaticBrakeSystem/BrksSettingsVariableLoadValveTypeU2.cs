namespace AtsPlugin.BrakeSystem
{
    public class BrksSettingsVariableLoadValveTypeU2 : AtsBehaviourSettingsBase
    {
        public double MinimumBcPressureKiloPascal { get; set; }
        public double MaximumBcPressureKiloPascal { get; set; }
        public double MaximumLoadRate { get; set; }
        public double InShotStartKiloPascal { get; set; }
        public double InShotEndKiloPascal { get; set; }
        public double InShotRate { get; set; }
    }
}
