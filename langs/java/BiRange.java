/**
 *   Copyright (c) Rich Hickey. All rights reserved.
 *   The use and distribution terms for this software are covered by the
 *   Common Public License 1.0 (http://opensource.org/licenses/cpl.php)
 *   which can be found in the file CPL.TXT at the root of this distribution.
 *   By using this software in any fashion, you are agreeing to be bound by
 *       the terms of this license.
 *   You must not remove this notice, or any other, from this software.
 **/

/* rich Apr 1, 2008 */

package clojure.lang;

public class Range extends ASeq implements IReduce{
final int end;
final int n;
final int dir;

public Range(int start, int end){
        this.end = end;
        this.n = start;
        this.dir = calcDir();
}

public Range(IPersistentMap meta, int start, int end){
        super(meta);
        this.end = end;
        this.n = start;
        this.dir = calcDir();
}

private int calcDir(){
        this.dir = n < end ? 1 : -1;
}

public Obj withMeta(IPersistentMap meta){
        if(meta == meta())
                return this;
        return new Range(meta(), end, n);
}

public Object first(){
        return n;
}

public ISeq rest(){
        if(n < end-1)
                return new Range(_meta, n + 1, end);
        return null;
}

public Object reduce(IFn f) throws Exception{
        Object ret = n;
        for(int x = n+1;x < end;x++)
                ret = f.invoke(ret, x);
        return ret;
}

public Object reduce(IFn f, Object start) throws Exception{
        Object ret = f.invoke(start,n);
        for(int x = n+1;x < end;x++)
                ret = f.invoke(ret, x);
        return ret;
}

}
