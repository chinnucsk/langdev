import java.util.*;

public class Identification
{
    private static int  _loops = 100000000;

    public HashMap<Object,Launcher> _lookup;
    public HashMap<String,Integer>  _counts;
    public Launcher _ln = new Launcher();

    public Identification() {
        _lookup = new HashMap<Object,Launcher>();
        _counts = new HashMap<String,Integer>();
        _counts.put( Boolean.class.getName(), new Integer(0));
        _counts.put( Integer.class.getName(), new Integer(0));
        _counts.put( Byte.class.getName(), new Integer(0));
        _counts.put( Character.class.getName(), new Integer(0));
        _counts.put( Float.class.getName(), new Integer(0));
        _counts.put( String.class.getName(), new Integer(0));
    }

    private String lessDumbLookup( Class cls) {
        Launcher ln = _lookup.get( cls);

        return ln.go( cls.getName());
    }

    private String dumbLookup( Object obj) {
        String name = obj.getClass().getName();

        Launcher ln = _lookup.get( name);
        ln.go( name);

        return name;
    }

    private String instanceOfId( Object obj) {
        if( obj instanceof Boolean) {
            return obj.getClass().getName();
        }
        else if( obj instanceof Integer) {
            return obj.getClass().getName();
        }
        else if( obj instanceof Byte) {
            return obj.getClass().getName();
        }
        else if( obj instanceof Character) {
            return obj.getClass().getName();
        }
        else if( obj instanceof Float) {
            return obj.getClass().getName();
        }
        else if( obj instanceof String) {
            return obj.getClass().getName();
        }
        else {
            return "not found";
        }
    }

    private String classStringCompare( Object obj) {
        String name = obj.getClass().getName();

        if( name.equals( Boolean.class.getName())) {
            return obj.getClass().getName();
        }
        else if( name.equals( Integer.class.getName())) {
            return obj.getClass().getName();
        }
        else if( name.equals( Byte.class.getName())) {
            return obj.getClass().getName();
        }
        else if( name.equals( Character.class.getName())) {
            return obj.getClass().getName();
        }
        else if( name.equals( Float.class.getName())) {
            return obj.getClass().getName();
        }
        else if( name.equals( String.class.getName())) {
            return obj.getClass().getName();
        }
        else {
            return "not found";
        }
    }

    private class Launcher
    {
        public String go( String name) {
            _counts.put( name, _counts.get( name).intValue() + 1);

            return name;
        }
    }

    public static void main( String args[]) {
        Identification ider = new Identification();
        Random rand = new Random( System.currentTimeMillis());

        Object[] classes = {new Boolean( true), new Integer( 42), new Byte( Byte.MAX_VALUE), new Character( 'f'), new Float( 9.0f), new String( "foo")};
        int mode = 0;
        String modeStr = "";
        long _start, _stop, _elapsed;

        if( args.length == 0) {
            System.out.println( "You must suppy an identification strategy");
        }
        else {
            modeStr = args[0].toLowerCase();
        }

        if( modeStr.equals( "instanceof")) {
            mode = 1;
        }
        else if( modeStr.equals( "classname")) {
            mode = 2;
        }
        else if( modeStr.equals( "dumblookup")) {
            ider._lookup.put( Boolean.class.getName(), ider._ln);
            ider._lookup.put( Integer.class.getName(), ider._ln);
            ider._lookup.put( Byte.class.getName(), ider._ln);
            ider._lookup.put( Float.class.getName(), ider._ln);
            ider._lookup.put( Character.class.getName(), ider._ln);
            ider._lookup.put( String.class.getName(), ider._ln);

            mode = 3;
        }
        else if( modeStr.equals( "lessdumblookup")) {
            ider._lookup.put( Boolean.class, ider._ln);
            ider._lookup.put( Integer.class, ider._ln);
            ider._lookup.put( Byte.class, ider._ln);
            ider._lookup.put( Float.class, ider._ln);
            ider._lookup.put( Character.class, ider._ln);
            ider._lookup.put( String.class, ider._ln);

            mode = 4;
        }

        _start = System.currentTimeMillis();

        for( int i=0; i<_loops; i++) {
            switch( mode) {
            case 1:
                ider._ln.go( ider.instanceOfId( classes[rand.nextInt( 6)]));
                break;
            case 2:
                ider._ln.go( ider.classStringCompare( classes[rand.nextInt( 6)]));
                break;
            case 3:
                ider.dumbLookup( classes[rand.nextInt( 6)]);
                break;
            case 4:
                ider.lessDumbLookup( classes[rand.nextInt( 6)].getClass());
                break;
            default:
                // Error mode
                System.out.println( "Mode " + modeStr + " not valid");
                System.exit(1);
            }
        }

        _stop = System.currentTimeMillis();
        _elapsed = _stop - _start;

        System.out.println( "Mode " + modeStr + " ran in " + _elapsed);
        System.out.println( ider._counts.toString());
    }
}
